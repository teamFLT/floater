#include "AttributeMacro.h"

flt::reflection::AttributeMacro::AttributeMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token):
	Macro(depth, line, column, std::move(token)),
	_isValid(false) {}

void flt::reflection::AttributeMacro::OnLineVisited()
{
	_isValid = true;
}

void flt::reflection::AttributeMacro::OnNextDataMemberAppeared()
{
	_isValid = false;
}
