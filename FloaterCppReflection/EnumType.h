#pragma once
#include <string>
#include <vector>

#include "ReflectedMember.h"

namespace flt
{
	namespace reflection
	{
		class EnumType : public ReflectedMember
		{
		public:
			EnumType(unsigned depth, unsigned line, unsigned column, std::string&& usr,std::string&& name);

		public:
			std::string Serialize() override;

		public:
			std::string usr;
			std::string name;
			std::vector<std::string> elements;
		};
	}
}
