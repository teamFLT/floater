#pragma once
#include <string>
#include <vector>

#include "Macro.h"

namespace flt
{
	namespace reflection
	{
		class MacroFactory
		{
		public:
			static Macro* Create(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& tokens);
		};
	}
}
