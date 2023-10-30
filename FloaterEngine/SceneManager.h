#pragma once
#include <vector>

#include "Scene.h"

namespace flt
{
	namespace engine
	{
		class SceneManager
		{
		public:
			static void LoadScene(std::string name);
			static void LoadScene(int index);
			static void UnloadCurrentScene();

		private:
			static std::vector<Scene*> g_scenes;
			static Scene* g_currentScene;
		};

	}
}
