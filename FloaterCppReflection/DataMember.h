#pragma once
#include <string>

#include "ReflectedMember.h"

namespace flt
{
	namespace reflection
	{
		class DataMember : public ReflectedMember
		{
		public:
			DataMember(unsigned depth, unsigned line, unsigned column);

			std::string Serialize() override;
		};
	}
}
