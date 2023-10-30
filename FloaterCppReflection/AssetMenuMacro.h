#pragma once
#include "Macro.h"

namespace flt
{
	namespace reflection
	{
		class AssetMenuMacro : public Macro
		{
		public:
			AssetMenuMacro(unsigned depth,unsigned line, unsigned column, std::vector<std::string>&& token);

			std::string Serialize() override;

		public:
			std::string assetMenu;
		};
	}
}
