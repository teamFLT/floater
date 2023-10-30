#include "ReadOnlyMacro.h"

#include "CppClassAnalyzer.h"

flt::reflection::ReadOnlyMacro::ReadOnlyMacro(unsigned depth, unsigned line, unsigned column,std::vector<std::string>&& token) :
	Macro(depth, line, column, std::move(token)) {}

void flt::reflection::ReadOnlyMacro::OnLineVisited()
{
	CppClassAnalyzer::readOnlyFlag = true;
}

void flt::reflection::ReadOnlyMacro::OnNextDataMemberAppeared()
{
	CppClassAnalyzer::readOnlyFlag = false;
}
