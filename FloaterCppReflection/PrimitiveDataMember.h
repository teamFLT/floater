#pragma once
#include "DataMember.h"

namespace flt
{
	namespace reflection
	{
		class PrimitiveDataMember : public DataMember
		{
		public:
			PrimitiveDataMember(unsigned depth, unsigned line, unsigned column, std::string&& type, std::string&& name, std::string&& defaultValue = "");
			std::string Serialize() override;
		public:
			std::string type;
			std::string name;
			std::string defaultValue;
		};
	}
}
