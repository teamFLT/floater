#include "AssetMenuMacro.h"

flt::reflection::AssetMenuMacro::AssetMenuMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token) :
	Macro(depth, line, column, std::move(token))
{
	assetMenu = _tokens[2];
}

std::string flt::reflection::AssetMenuMacro::Serialize()
{
	return std::string(depth, '\t') + "[asset menu] " + assetMenu + "\n";
}
