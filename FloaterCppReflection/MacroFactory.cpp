#include "MacroFactory.h"

#include <cassert>

#include "AssetTypeMacro.h"
#include "AssetMenuMacro.h"
#include "AssetBuildIndexMacro.h"
#include "AssetIconMacro.h"
#include "DefaultValueMacro.h"
#include "ReadOnlyMacro.h"
#include "HideInInspectorMacro.h"
#include "SerializeFieldMacro.h"

flt::reflection::Macro* flt::reflection::MacroFactory::Create(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& tokens)
{
	if (tokens[0] == "ASSET_MENU")
	{
		return new ReadOnlyMacro(depth, line, column, std::move(tokens));
	}
	else if (tokens[0] == "ASSET_ICON")
	{
		return new AssetIconMacro(depth, line, column, std::move(tokens));
	}
	else if (tokens[0] == "ASSET_BUILD_INDEX")
	{
		return new AssetBuildIndexMacro(depth, line, column, std::move(tokens));
	}
	else if (tokens[0] == "SERIALIZE_FIELD")
	{
		return new SerializeFieldMacro(depth, line, column, std::move(tokens));
	}
	else if (tokens[0] == "HIDE_IN_INSPECTOR")
	{
		return new HideInInspectorMacro(depth, line, column, std::move(tokens));
	}
	else if (tokens[0] == "READ_ONLY")
	{
		return new ReadOnlyMacro(depth, line, column, std::move(tokens));
	}
	else if (tokens[0] == "DEFAULT_VALUE")
	{
		return new DefaultValueMacro(depth, line, column, std::move(tokens));
	}
	assert(false);
	return nullptr;
}
