#include "AssetTypeMacro.h"

flt::reflection::AssetTypeMacro::AssetTypeMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token) :
	Macro(depth, line, column, std::move(token))
{
	assetType = _tokens[2];
}

std::string flt::reflection::AssetTypeMacro::Serialize()
{
	return std::string(depth, '\t') + "[asset type] " + assetType + "\n";
}
