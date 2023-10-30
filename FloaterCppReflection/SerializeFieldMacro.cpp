#include "SerializeFieldMacro.h"

#include "CppClassAnalyzer.h"

flt::reflection::SerializeFieldMacro::SerializeFieldMacro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& token) :
	AttributeMacro(depth, line, column, std::move(token)){}

void flt::reflection::SerializeFieldMacro::OnLineVisited()
{
	AttributeMacro::OnLineVisited();
	CppClassAnalyzer::showFlag = true;
	CppClassAnalyzer::hideFlag = false;
}

void flt::reflection::SerializeFieldMacro::OnNextDataMemberAppeared()
{
	if(_isValid)
	{
		CppClassAnalyzer::showFlag = false;
	}
	AttributeMacro::OnNextDataMemberAppeared();
}
