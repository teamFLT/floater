#include "ReflectedClass.h"

flt::reflection::ReflectedClass::ReflectedClass(unsigned depth, ReflectedClass* parent) :
	ReflectedObject(depth), parent(parent){}

std::string flt::reflection::ReflectedClass::Serialize()
{
	std::string result;
	result.append(std::string(depth, '\t'));
	result.append("[class] "+name+"\n");
	result.append(std::string(depth, '\t'));
	result.append("[usr] "+usr+"\n");
	for (auto rawBaseClass : rawBaseClasses)
	{
		result.append(std::string(depth, '\t'));
		result.append("[base class] " + rawBaseClass + "\n");
	}
	for (auto macro : macros)
	{
		result.append(std::string(depth, '\t'));
		result.append(macro->Serialize());
	}
	for (auto nestedClass : nestedClasses)
	{
		result.append(std::string(depth, '\t'));
		result.append(nestedClass->Serialize());
	}
	for (auto enumType : enumTypes)
	{
		result.append(std::string(depth, '\t'));
		result.append(enumType->Serialize());
	}
	for (auto dataMember : dataMembers)
	{
		result.append(std::string(depth, '\t'));
		result.append(dataMember->Serialize());
	}
	result.append(std::string(depth, '\t'));
	result.append("[/class]\n");
	return result;
}

void flt::reflection::ReflectedClass::CheckLine(unsigned line)
{
	for (auto macro : macros)
	{
		if (line >= macro->GetLine() && !macro->IsVisited())
		{
			macro->OnLineVisited();
			macro->SetVisited(true);
			return;
		}
	}
}

void flt::reflection::ReflectedClass::DataMemberAppear(unsigned line)
{
	for (auto macro : macros)
	{
		if (line > macro->GetLine())
		{
			macro->OnNextDataMemberAppeared();
		}
	}
}

void flt::reflection::ReflectedClass::ParseEnd()
{
	for (auto macro : macros)
	{
		macro->OnParseEnd();
	}
}
