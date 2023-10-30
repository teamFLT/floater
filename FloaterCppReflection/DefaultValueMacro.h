#pragma once
#include "AttributeMacro.h"

namespace flt
{
	namespace reflection
	{
		class DefaultValueMacro : public AttributeMacro
		{
		public:
			DefaultValueMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token);
			void OnLineVisited() override;
			void OnNextDataMemberAppeared() override;

		private:
			std::string _defaultValue;
		};
	}
}