#pragma once
#include <string>

namespace flt
{
	namespace engine
	{
		class IProperty
		{
		public:
			virtual std::string GetType() abstract;
			virtual std::string GetName() abstract;
			virtual std::string GetValue() abstract;
			virtual void SetValue(std::string p_value) abstract;
		};
	}
}
