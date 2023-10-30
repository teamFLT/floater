#include "PointerDataMember.h"

flt::reflection::PointerDataMember::PointerDataMember(unsigned depth, unsigned line, unsigned column, std::string&& type, std::string&& name, std::string&& usr) :
	DataMember(depth, line, column),
	type(std::move(type)),
	name(std::move(name)),
	usr(std::move(usr)) {}

std::string flt::reflection::PointerDataMember::Serialize()
{
	return std::string(depth, '\t') + "[" + type + "] " + name + "\n";
}
