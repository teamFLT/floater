#pragma once
#include "Component.h"

namespace flt
{
	namespace engine
	{
		class GameObject;

		class Behaviour : public Component
		{
		public:
			Behaviour(GameObject* gameObject,std::string id,std::string name);
			~Behaviour() override;

			bool enabled;
			bool isActiveAndEnabled;
		};
	}
}
