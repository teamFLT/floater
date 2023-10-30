#include "AssetIconMacro.h"

flt::reflection::AssetIconMacro::AssetIconMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token) :
	Macro(depth, line, column, std::move(token))
{
	_assetIcon = _tokens[2];
}

std::string flt::reflection::AssetIconMacro::Serialize()
{
	return std::string(depth, '\t') + "[AssetIcon] " + _assetIcon + "\n";
}
