#pragma once
#include <vector>

#include "ReflectedMember.h"

namespace flt
{
	namespace reflection
	{
		class MemberFunction : public ReflectedMember
		{
		public:
			MemberFunction(unsigned depth, unsigned line, unsigned column, std::string&& usr, std::string&& name);

		public:
			std::string Serialize() override;

		public:
			std::string usr;
			std::string returnType;
			std::string name;
			std::vector<std::string> parmeter;
		};
	}
}

