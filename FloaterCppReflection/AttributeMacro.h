#pragma once
#include "Macro.h"

namespace flt
{
	namespace reflection
	{
		class AttributeMacro : public Macro
		{
		public:
			AttributeMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token);
			void OnLineVisited() override;
			void OnNextDataMemberAppeared() override;

		protected:
			bool _isValid;
		};
	}
}
