#include "AssetBuildIndexMacro.h"

flt::reflection::AssetBuildIndexMacro::AssetBuildIndexMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token) :
	Macro(depth, line, column, std::move(token))
{
	_buildIndex = _tokens[2];
}

std::string flt::reflection::AssetBuildIndexMacro::Serialize()
{
	return std::string(depth, '\t') + "[asset build index] " + _buildIndex + "\n";
}
