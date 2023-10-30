#include "EnumDataMember.h"

flt::reflection::EnumDataMember::EnumDataMember(unsigned depth, unsigned line, unsigned column, std::string&& type, std::string&& name, std::string&& usr, std::string&& defaultValue) :
	DataMember(depth, line, column),
	type(std::move(type)),
	name(std::move(name)),
	usr(std::move(usr)),
	defaultValue(std::move(defaultValue)) {}

std::string flt::reflection::EnumDataMember::Serialize()
{
	return std::string(depth, '\t') + "[" + type + "] " + name + " " + usr + " " + defaultValue + "\n";
}
