#pragma once
#include "MonoBehaviour.h"
#include "Vector3f.h"

namespace flt
{
	namespace engine
	{
		class Transform : public MonoBehaviour
		{
		public:
			Vector3f position;
			Vector3f rotation;
			Vector3f scale;
		};
	}
}
