#pragma once
#include "DataMember.h"

namespace flt
{
	namespace reflection
	{
		class EnumDataMember : public DataMember
		{
		public:
			EnumDataMember(unsigned depth, unsigned line, unsigned column, std::string&& type, std::string&& name, std::string&& usr, std::string&& defaultValue = "");
			std::string Serialize() override;

			std::string type;
			std::string name;
			std::string usr;
			std::string defaultValue;
		};
	}
}