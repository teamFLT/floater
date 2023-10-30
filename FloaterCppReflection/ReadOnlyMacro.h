#pragma once
#include "Macro.h"

namespace flt
{
	namespace reflection
	{
		class ReadOnlyMacro : public Macro
		{
		public:
			ReadOnlyMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token);
			void OnLineVisited() override;
			void OnNextDataMemberAppeared() override;

		};
	}
}
