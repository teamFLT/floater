#include "EnumType.h"

flt::reflection::EnumType::EnumType(unsigned depth, unsigned line, unsigned column, std::string&& usr, std::string&& name) :
	ReflectedMember(depth, line, column),
	usr(std::move(usr)),
	name(std::move(name)){}

std::string flt::reflection::EnumType::Serialize()
{
	std::string result;
	result.append(std::string(depth, '\t'));
	result.append("[enum] " + name+" "+usr + " \n");
	for (auto element : elements)
	{
		result.append(std::string(depth, '\t'));
		result.append("<"+element+">\n");
	}
	result.append(std::string(depth, '\t'));
	result.append("[/enum]\n");
	return result;
}
