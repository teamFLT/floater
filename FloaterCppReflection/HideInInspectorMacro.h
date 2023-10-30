#pragma once
#include "AttributeMacro.h"

namespace flt
{
	namespace reflection
	{
		class HideInInspectorMacro : public AttributeMacro
		{
		public:
			HideInInspectorMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token);
			void OnLineVisited() override;
			void OnNextDataMemberAppeared() override;

		};
	}
}