#pragma once
#include "AttributeMacro.h"

namespace flt
{
	namespace reflection
	{
		class SerializeFieldMacro : public AttributeMacro
		{
		public:
			SerializeFieldMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token);
			void OnLineVisited() override;
			void OnNextDataMemberAppeared() override;
	
		};
	}
}
