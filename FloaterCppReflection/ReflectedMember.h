#pragma once
#include <string>

#include "ReflectedObject.h"

namespace flt
{
	namespace reflection
	{
		class ReflectedMember : public ReflectedObject
		{
		public:
			ReflectedMember(unsigned depth, unsigned line, unsigned column);
		protected:
			unsigned int _line;
			unsigned int _column;
		};
	}
}
