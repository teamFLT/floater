#include "Scene.h"

#include <cassert>

#include "GameObject.h"

void flt::engine::Scene::Bind(GameObject* gameObject)
{
	bindIDs.push_back(gameObject->GetInstanceID());
}

void flt::engine::Scene::Load()
{
	for (auto id : bindIDs)
	{
		GameObject* instance = dynamic_cast<GameObject*>(BaseObject::FindObjectByInstanceID(id));
		if(instance)
		{
			GameObjectManager::Load(instance);
		}
		else
		{
			assert(false);
		}
	}
}

void flt::engine::Scene::Unload()
{
	GameObjectManager::UnloadAllInstance();
}
