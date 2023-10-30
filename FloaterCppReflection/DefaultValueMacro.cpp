#include "DefaultValueMacro.h"

#include "CppClassAnalyzer.h"

flt::reflection::DefaultValueMacro::DefaultValueMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token) :
	AttributeMacro(depth, line, column, std::move(token))
{
	_defaultValue = _tokens[2];
}

void flt::reflection::DefaultValueMacro::OnLineVisited()
{
	AttributeMacro::OnLineVisited();
	CppClassAnalyzer::currentDefaultValue = _defaultValue;
}

void flt::reflection::DefaultValueMacro::OnNextDataMemberAppeared()
{
	if (_isValid)
	{
		CppClassAnalyzer::currentDefaultValue = "";
	}
	AttributeMacro::OnNextDataMemberAppeared();
}

