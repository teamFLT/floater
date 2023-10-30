#include "DataMemberFactory.h"

#include <cassert>

#include "EnumDataMember.h"
#include "PointerDataMember.h"
#include "PrimitiveDataMember.h"


flt::reflection::DataMember* flt::reflection::DataMemberFactory::Create(unsigned depth, unsigned line, unsigned column, CX_CXXAccessSpecifier accessSpecifier,const bool& hideFlag, const bool& showFlag, const bool& readOnlyFlag, std::string&& defaultValue, CXCursor cursor)
{
	if (showFlag)
	{
		return Construct(depth, line, column, accessSpecifier, hideFlag, showFlag, readOnlyFlag, std::move(defaultValue), cursor);
	}
	else if (!hideFlag)
	{
		switch (accessSpecifier)
		{
		case CX_CXXPublic: {
			return Construct(depth, line, column, accessSpecifier, hideFlag, showFlag, readOnlyFlag, std::move(defaultValue), cursor);
		case CX_CXXProtected:
			return nullptr;
		case CX_CXXPrivate:
			return nullptr;
		default: assert(false);
		}
		}
		return nullptr;
	}
	return nullptr;
}

flt::reflection::DataMember* flt::reflection::DataMemberFactory::Construct(unsigned depth, unsigned line, unsigned column, CX_CXXAccessSpecifier accessSpecifier,const bool& hideFlag, const bool& showFlag, const bool& readOnlyFlag, std::string&& defaultValue, CXCursor cursor)
{
	CXType classType = clang_getCursorType(cursor);
	CXCursorKind kind = clang_getCursorKind(cursor);

	std::string usr = clang_getCString(clang_getCursorUSR(cursor));
	std::string cursorString = clang_getCString(clang_getCursorSpelling(cursor));
	std::string typeString = clang_getCString(clang_getTypeSpelling(classType));


	if (kind == CXType_Elaborated)
	{
		CXType namedType = clang_Type_getNamedType(classType);
		std::string typeName = clang_getCString(clang_getTypeSpelling(namedType));
		typeName.erase(std::remove_if(typeName.begin(), typeName.end(), [](unsigned char c) { return std::isspace(c); }), typeName.end());
		if (namedType.kind == CXType_Enum)
		{
			CXCursor baseClassCursor = clang_getTypeDeclaration(classType); //부모 클래스 커서
			std::string baseClassUSR = clang_getCString(clang_getCursorUSR(baseClassCursor));

			return new EnumDataMember(depth, line, column, std::move(typeName), std::move(cursorString), std::move(baseClassUSR));

		}
	}
	else if (classType.kind == CXType_Pointer)
	{
		CXType pointeeType = clang_getPointeeType(classType);
		std::string pointeTypeUSR = clang_getCString(clang_getCursorUSR(clang_getTypeDeclaration(pointeeType)));

		return new PointerDataMember(depth, line, column, std::move(typeString), std::move(cursorString), std::move(pointeTypeUSR));
	}
	else
	{
		return new PrimitiveDataMember(depth, line, column, std::move(typeString), std::move(cursorString),std::move(defaultValue));
	}


}
