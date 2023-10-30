#pragma once
#include <vector>
#include <clang-c/Index.h>

#include "DataMember.h"

namespace flt
{
	namespace reflection
	{
		class DataMemberFactory
		{

		public:
			static DataMember* Create(unsigned depth, unsigned line, unsigned column, CX_CXXAccessSpecifier accessSpecifier, const bool& hideFlag, const bool& showFlag, const bool& readOnlyFlag, std::string&& currentDefaultValue, CXCursor cursor);
			static DataMember* Construct(unsigned depth, unsigned line, unsigned column, CX_CXXAccessSpecifier accessSpecifier, const bool& hideFlag, const bool& showFlag, const bool&
			                             readOnlyFlag, std::string&& currentDefaultValue, CXCursor cursor);
		};
	}
}