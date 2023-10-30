#pragma once
#include "DataMember.h"

namespace flt
{
	namespace reflection
	{
		class PointerDataMember : public DataMember
		{
		public:
			PointerDataMember(unsigned depth, unsigned line, unsigned column, std::string&& type, std::string&& name, std::string&& usr);
			std::string Serialize();

		public:
			std::string type;
			std::string name;
			std::string usr;
		};
	}
}
