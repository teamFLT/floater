#pragma once
#include "Macro.h"

namespace flt
{
	namespace reflection
	{
		class AssetTypeMacro : public Macro
		{
		public:
			AssetTypeMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token);

			std::string Serialize() override;

		private:
			std::string assetType;
		};
	}
}
