#include "PrimitiveDataMember.h"


flt::reflection::PrimitiveDataMember::PrimitiveDataMember(unsigned depth, unsigned line, unsigned column, std::string&& type, std::string&& name, std::string&& defaultValue) :
	DataMember(depth, line, column),
	type(std::move(type)),
	name(std::move(name)),
	defaultValue(std::move(defaultValue)) {}

std::string flt::reflection::PrimitiveDataMember::Serialize()
{
	return std::string(depth, '\t') + "[" + type + "] " + name + " " + defaultValue + "\n";
}
