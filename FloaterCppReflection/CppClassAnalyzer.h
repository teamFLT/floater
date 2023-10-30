#pragma once
#include <string>
#include <vector>
#include <clang-c/Index.h>

#include "ReflectedClass.h"

namespace flt
{
	namespace reflection
	{
		class CppClassAnalyzer
		{
		public:
			static void AnalyzeFile(std::string&& filepath);
			static ReflectedClass* AnalyzeClass(CXCursor child, ReflectedClass* reflectedClass);
			static void AnalyzeDirectory(std::string&& directory,bool&& recursive=false);
			static void ShowAnalyzedClassQueue();

		private:
			static void IncludeAdditionalProject(std::string&& directory);

			static CXCursor GetCursor(CXTranslationUnit unit);

			static CXTranslationUnit Translate(std::string&& filename);

			static std::vector<std::string>&& ParseMacroExpansion(CXTranslationUnit tu, CXCursor cursor);
			
			static std::string ExtractOriginalUSR(std::string&& crtpUSR);

			static CXChildVisitResult FileTracker(CXCursor child, CXCursor parent, CXClientData clientData);
			static CXChildVisitResult ClassVisitor(CXCursor child, CXCursor parent, CXClientData clientData);


		public:
			static unsigned depth;

			static bool hideFlag;
			static bool showFlag;
			static bool readOnlyFlag;
			static std::string currentDefaultValue;
			static std::vector<ReflectedClass*> analyzedClassQueue;

		private:
			static CXIndex s_index;
			static CX_CXXAccessSpecifier s_currentAccessSpecifier;
			static std::vector<std::string> s_additionalProject;
			static EnumType* s_currentEnumType;
		
		};

		
	}
}
