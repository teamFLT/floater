#pragma once
#include "BaseObject.h"

namespace flt
{
	namespace engine
	{
		class Scene : public BaseObject
		{
		public:
			void Bind(GameObject* gameObject);
			void Load();
			void Unload();
		public:
			std::vector<std::string> bindIDs;
		};
	}
}

