#include "CppClassAnalyzer.h"

#include <cassert>
#include <filesystem>
#include <iostream>

#include "DataMemberFactory.h"
#include "MacroFactory.h"


unsigned flt::reflection::CppClassAnalyzer::depth = 0;
CXIndex flt::reflection::CppClassAnalyzer::s_index;
CX_CXXAccessSpecifier flt::reflection::CppClassAnalyzer::s_currentAccessSpecifier;
std::vector<std::string> flt::reflection::CppClassAnalyzer::s_additionalProject;
std::vector<flt::reflection::ReflectedClass*> flt::reflection::CppClassAnalyzer::analyzedClassQueue;
flt::reflection::EnumType* flt::reflection::CppClassAnalyzer::s_currentEnumType;
bool flt::reflection::CppClassAnalyzer::hideFlag = false;
bool flt::reflection::CppClassAnalyzer::showFlag = false;
bool flt::reflection::CppClassAnalyzer::readOnlyFlag = false;
std::string flt::reflection::CppClassAnalyzer::currentDefaultValue;

void flt::reflection::CppClassAnalyzer::AnalyzeFile(std::string&& filepath)
{
	clang_visitChildren(GetCursor(Translate(std::move(filepath))), FileTracker, nullptr);
}

flt::reflection::ReflectedClass* flt::reflection::CppClassAnalyzer::AnalyzeClass(CXCursor child, ReflectedClass* reflectedClass)
{
	clang_visitChildren(child, ClassVisitor, reflectedClass);
	return reflectedClass;
}

void flt::reflection::CppClassAnalyzer::AnalyzeDirectory(std::string&& directory, bool&& recursive)
{
	for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(std::filesystem::path(directory)))
	{
		AnalyzeFile(std::move(entry.path().generic_string()));
	}
}

void flt::reflection::CppClassAnalyzer::IncludeAdditionalProject(std::string&& directory)
{
	s_additionalProject.push_back(directory);
}

CXChildVisitResult flt::reflection::CppClassAnalyzer::ClassVisitor(CXCursor child, CXCursor parent, CXClientData clientData)
{
	ReflectedClass* reflectedClass = reinterpret_cast<ReflectedClass*>(clientData);

	CXString filename;
	unsigned line, column;

	CXType classType = clang_getCursorType(child);
	CXCursorKind kind = clang_getCursorKind(child);
	CXSourceLocation location = clang_getCursorLocation(child);

	clang_getPresumedLocation(location, &filename, &line, &column);

	std::string usr = clang_getCString(clang_getCursorUSR(child));
	std::string cursorString = clang_getCString(clang_getCursorSpelling(child));
	std::string typeString = clang_getCString(clang_getTypeSpelling(classType));


	if (clang_Location_isFromMainFile(clang_getCursorLocation(child)))
	{

		reflectedClass->CheckLine(line);

		switch (kind)
		{
		case CXCursor_MacroExpansion:
		{
			std::vector<std::string> macroTokens = ParseMacroExpansion(clang_Cursor_getTranslationUnit(child), child); //매크로 토큰화
			auto macro = MacroFactory::Create(depth, line, column, std::move(macroTokens));
			macro->OnExpanded();
		}
		break;
		case CXCursor_CXXBaseSpecifier:
		{
			CXCursor baseClassCursor = clang_getTypeDeclaration(classType); //부모 클래스 커서
			std::string baseClassUsr = clang_getCString(clang_getCursorUSR(baseClassCursor)); //부모 클래스 usr
			reflectedClass->rawBaseClasses.insert(ExtractOriginalUSR(std::move(baseClassUsr)));
		}
		break;
		case CXCursor_ClassDecl:
		case CXCursor_ClassTemplate:
		{
			if (clang_isCursorDefinition(clang_getCursorDefinition(child)))
			{
				auto newClass = new ReflectedClass(depth, reflectedClass);
				reflectedClass->nestedClasses.push_back(newClass);
				newClass->name = typeString;
				newClass->usr = usr;
				depth++;
				AnalyzeClass(child, newClass);
				depth--;
				return CXChildVisit_Continue;
			}
			break;
		}
		case CXCursor_StructDecl:
		{
			if (clang_isCursorDefinition(clang_getCursorDefinition(child)))
			{
				auto newClass = new ReflectedClass(depth, reflectedClass);
				reflectedClass->nestedClasses.push_back(newClass);
				newClass->isStruct = true;
				newClass->name = typeString;
				newClass->usr = usr;
				depth++;
				AnalyzeClass(child, newClass);
				depth--;
				return CXChildVisit_Continue;
			}
			break;
		}

		case CXCursor_EnumDecl:
		{
			s_currentEnumType = new EnumType(depth, line, column, std::move(usr), std::move(typeString));
			reflectedClass->enumTypes.push_back(s_currentEnumType);
			break;
		}
		case CXCursor_EnumConstantDecl:
		{
			if (s_currentEnumType)
			{
				s_currentEnumType->elements.push_back(cursorString);
			}
			else
			{
				assert(false);
			}
			break;
		}
		case CXCursor_FunctionDecl:
			{
				
			}
			break;
		case CXCursor_FieldDecl:
		{
			auto dataMember = DataMemberFactory::Create(depth, line, column, s_currentAccessSpecifier, hideFlag, showFlag, readOnlyFlag, std::move(currentDefaultValue), child);
			if (dataMember)
			{
				reflectedClass->dataMembers.push_back(dataMember);
				reflectedClass->DataMemberAppear(line);
			}
			break;
		}
		case CXCursor_CXXAccessSpecifier:
			s_currentAccessSpecifier = clang_getCXXAccessSpecifier(child);
			break;
		default:
			break;
		}
		return CXChildVisit_Recurse;
	}
	else
	{
		return CXChildVisit_Recurse;
	}
}

std::vector<std::string>&& flt::reflection::CppClassAnalyzer::ParseMacroExpansion(CXTranslationUnit tu, CXCursor cursor)
{
	std::vector<std::string> result;

	CXSourceRange range = clang_getCursorExtent(cursor);
	CXToken* tokens;
	unsigned int numTokens;
	clang_tokenize(tu, range, &tokens, &numTokens);

	for (unsigned int i = 0; i < numTokens; ++i)
	{
		CXToken token = tokens[i];
		CXString tokenSpelling = clang_getTokenSpelling(tu, token);
		result.push_back(clang_getCString(tokenSpelling));
		clang_disposeString(tokenSpelling);
	}

	clang_disposeTokens(tu, tokens, numTokens);
	return std::move(result);
}

std::string flt::reflection::CppClassAnalyzer::ExtractOriginalUSR(std::string&& crtpUSR)
{
	size_t crtpPos = crtpUSR.find(">#$");
	if (crtpPos == std::string::npos) {
		return crtpUSR;
	}

	std::string result = crtpUSR.substr(0, crtpPos);

	size_t templatePos = result.find_last_of('S@');

	result.replace(templatePos - 1, 2, "ST>1#T@");

	return result;
}

CXChildVisitResult flt::reflection::CppClassAnalyzer::FileTracker(CXCursor child, CXCursor parent,
	CXClientData clientData)
{
	CXString filename;
	unsigned line, column;

	CXType classType = clang_getCursorType(child);
	CXCursorKind kind = clang_getCursorKind(child);
	CXSourceLocation location = clang_getCursorLocation(child);

	clang_getPresumedLocation(location, &filename, &line, &column);

	std::string usr = clang_getCString(clang_getCursorUSR(child));
	std::string cursorString = clang_getCString(clang_getCursorSpelling(child));
	std::string typeString = clang_getCString(clang_getTypeSpelling(classType));


	if (clang_Location_isFromMainFile(clang_getCursorLocation(child)))
	{

		switch (kind)
		{
		case CXCursor_StructDecl:
		{
			auto newClass = new ReflectedClass(depth);
			newClass->isStruct = true;
			newClass->name = typeString;
			newClass->usr = usr;
			s_currentAccessSpecifier = CX_CXXPublic;
			depth++;
			analyzedClassQueue.push_back(AnalyzeClass(child, newClass));
			depth--;
		}
		return CXChildVisit_Continue;
		case CXCursor_ClassDecl:
		case CXCursor_ClassTemplate:
		{
			if (clang_isCursorDefinition(clang_getCursorDefinition(child)))
			{
				auto newClass = new ReflectedClass(depth);
				newClass->name = typeString;
				newClass->usr = usr;
				s_currentAccessSpecifier = CX_CXXPrivate;
				depth++;
				analyzedClassQueue.push_back(AnalyzeClass(child, newClass));
				depth--;
			}
		}
		return CXChildVisit_Continue;
		}
	}
}

CXCursor flt::reflection::CppClassAnalyzer::GetCursor(CXTranslationUnit unit)
{
	return clang_getTranslationUnitCursor(unit);
}

CXTranslationUnit flt::reflection::CppClassAnalyzer::Translate(std::string&& filename)
{
	s_index = clang_createIndex(0, 0);

	std::vector<const char*> commandLineArgs;

	for (auto project : s_additionalProject)
	{
		std::string tmp = "-I../" + project;
		commandLineArgs.push_back(tmp.c_str());
	}
	commandLineArgs.push_back("-std=c99");
	commandLineArgs.push_back("-std=c++20");
	commandLineArgs.push_back("-E");

	auto rawCommandLineArgs = commandLineArgs.data();

	auto unit = clang_parseTranslationUnit(s_index,
		filename.c_str(),
		rawCommandLineArgs,
		static_cast<int>(commandLineArgs.size()),
		nullptr,
		0,
		CXTranslationUnit_None);
	return unit;
}

void flt::reflection::CppClassAnalyzer::ShowAnalyzedClassQueue()
{
	for (ReflectedClass* element : analyzedClassQueue)
	{
		std::cout << element->Serialize();
	}
}

