#pragma once
#include <functional>
#include <string>

namespace flt
{
	namespace engine
	{
		class GameObject;

		class GameObjectManager
		{
			using Adapter = std::function<GameObject* (GameObject*)>;
			using Builder = std::function<GameObject* (GameObject*)>;

		public:
			GameObjectManager();
			~GameObjectManager();

			bool Initialize();
			bool Update();
			bool LateUpdate();

			static void Bind(std::string instanceID, Adapter adapter, Builder builder);
			static GameObject* Create(std::string instanceID, std::string name);
			static GameObject* Adapt(GameObject* instance); //Component 연결
			static GameObject* Build(GameObject* instance); //Component FProperty 구축
			static void Load(GameObject* instance);
			static void UnloadAllInstance();
			static void Destroy(GameObject* instance);

		private:
			static std::unordered_map<std::string, Adapter> g_adapters;
			static std::unordered_map<std::string, Builder> g_builders;
			static std::unordered_map<std::string, GameObject*> g_gameObjects;
			static std::vector<GameObject*>  g_instanceBuffer;
			static std::vector<GameObject*>  g_instiateBuffer;
			static std::vector<GameObject*>  g_destroyBuffer;
		};
	}
}
