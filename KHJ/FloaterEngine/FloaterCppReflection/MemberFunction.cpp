#include "MemberFunction.h"

flt::reflection::MemberFunction::MemberFunction(unsigned depth, unsigned line, unsigned column, std::string&& usr,
	std::string&& name) : ReflectedMember(depth, line, column)
{

}

std::string flt::reflection::MemberFunction::Serialize()
{
	return ReflectedMember::Serialize();
}
