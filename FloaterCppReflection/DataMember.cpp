#include "DataMember.h"


flt::reflection::DataMember::DataMember(unsigned depth, unsigned line, unsigned column) :
	ReflectedMember(depth, line, column) {}

std::string flt::reflection::DataMember::Serialize()
{
	return "";
}
