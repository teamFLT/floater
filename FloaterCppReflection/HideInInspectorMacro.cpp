#include "HideInInspectorMacro.h"

#include "CppClassAnalyzer.h"

flt::reflection::HideInInspectorMacro::HideInInspectorMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token) :
	AttributeMacro(depth, line, column, std::move(token)) {}

void flt::reflection::HideInInspectorMacro::OnLineVisited()
{
	AttributeMacro::OnLineVisited();
	CppClassAnalyzer::showFlag = false;
	CppClassAnalyzer::hideFlag = true;
}

void flt::reflection::HideInInspectorMacro::OnNextDataMemberAppeared()
{
	if (_isValid)
	{
		CppClassAnalyzer::hideFlag = false;
	}
	AttributeMacro::OnNextDataMemberAppeared();
}
