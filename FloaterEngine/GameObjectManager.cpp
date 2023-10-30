#include "GameObject.h"
#include "GameObjectManager.h"

using Adapter = std::function<flt::engine::GameObject* (flt::engine::GameObject*)>;
using Builder = std::function<flt::engine::GameObject* (flt::engine::GameObject*)>;

std::unordered_map<std::string, Adapter>  flt::engine::GameObjectManager::g_adapters;
std::unordered_map<std::string, Builder>  flt::engine::GameObjectManager::g_builders;
std::unordered_map<std::string, flt::engine::GameObject*> flt::engine::GameObjectManager::g_gameObjects;
std::vector<flt::engine::GameObject*> flt::engine::GameObjectManager::g_instanceBuffer;
std::vector<flt::engine::GameObject*> flt::engine::GameObjectManager::g_instiateBuffer;
std::vector<flt::engine::GameObject*> flt::engine::GameObjectManager::g_destroyBuffer;

flt::engine::GameObjectManager::GameObjectManager()
{
}

flt::engine::GameObjectManager::~GameObjectManager()
{
}

bool flt::engine::GameObjectManager::Initialize()
{
	return true;
}

bool flt::engine::GameObjectManager::Update()
{
	for (auto instance : g_instiateBuffer)
	{
		g_instanceBuffer.push_back(instance);
	}
	for (auto instance : g_destroyBuffer)
	{
		Destroy(instance);
	}
	for (auto instance : g_instanceBuffer)
	{
		instance->Start();
		instance->Update();
	}
	return true;
}

bool flt::engine::GameObjectManager::LateUpdate()
{
	for (auto instance : g_instanceBuffer)
	{
		instance->LateUpdate();
	}
	return true;
}

void flt::engine::GameObjectManager::Bind(std::string instanceID, Adapter adapter, Builder builder)
{
	g_adapters.insert(std::make_pair(instanceID, adapter));
	g_builders.insert(std::make_pair(instanceID, builder));
}

flt::engine::GameObject* flt::engine::GameObjectManager::Create(std::string instanceID,std::string name)
{
	GameObject* instance = g_adapters[instanceID](new GameObject(instanceID, name));
	g_gameObjects.insert(std::make_pair(instanceID, instance));
	return instance;
}

flt::engine::GameObject* flt::engine::GameObjectManager::Adapt(GameObject* instance)
{
	return g_adapters[instance->GetInstanceID()](instance);
}

flt::engine::GameObject* flt::engine::GameObjectManager::Build(GameObject* instance)
{
	return g_builders[instance->GetInstanceID()](instance);
}

void flt::engine::GameObjectManager::Load(GameObject* instance)
{
	g_instiateBuffer.push_back(instance);
	instance->Awake(); //Awake 호출 시점
}

void flt::engine::GameObjectManager::UnloadAllInstance()
{
	for (auto instance : g_instanceBuffer)
	{
		if(!instance->_dontDestroyFlag)
		{
			instance->Destroy(instance);
		}
	}
}

void flt::engine::GameObjectManager::Destroy(GameObject* instance)
{
	instance->OnDestroy();
	g_destroyBuffer.push_back(instance);
}
