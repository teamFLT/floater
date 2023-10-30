#include "Macro.h"

flt::reflection::Macro::Macro(unsigned depth, unsigned line, unsigned column, std::vector<std::string>&& tokens) :
	ReflectedMember(depth, line, column),
	_tokens(tokens),
	_isVisited(false)
{

}

void flt::reflection::Macro::OnLineVisited()
{

}

void flt::reflection::Macro::OnNextDataMemberAppeared()
{

}


void flt::reflection::Macro::OnExpanded()
{

}

void flt::reflection::Macro::OnParseEnd()
{

}

std::string flt::reflection::Macro::Serialize()
{
	return "";
}

unsigned flt::reflection::Macro::GetLine()
{
	return _line;
}

bool flt::reflection::Macro::IsVisited()
{
	return _isVisited;
}

void flt::reflection::Macro::SetVisited(bool value)
{
	_isVisited = value;
}



