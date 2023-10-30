#pragma once
#include "Macro.h"

namespace flt
{
	namespace reflection
	{
		class AssetIconMacro : public Macro
		{
		public:
			AssetIconMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token);

			std::string Serialize() override;

		private:
			std::string _assetIcon;
		};
	}
}
