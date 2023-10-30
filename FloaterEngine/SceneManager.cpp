#include "SceneManager.h"

std::vector<flt::engine::Scene*> flt::engine::SceneManager::g_scenes;
flt::engine::Scene* flt::engine::SceneManager::g_currentScene;

void flt::engine::SceneManager::LoadScene(std::string name)
{
	UnloadCurrentScene();
	auto scene = std::find_if(g_scenes.begin(), g_scenes.end(), [&](Scene* scene)
		{
			return scene->ToString() == name;
		});
	(*scene)->Load();
	g_currentScene = (*scene);
}

void flt::engine::SceneManager::LoadScene(int index)
{
	g_scenes[index]->Load();
	g_currentScene = g_scenes[index];
}

void flt::engine::SceneManager::UnloadCurrentScene()
{
	if (g_currentScene)
	{
		g_currentScene->Unload();
		g_currentScene = nullptr;
	}
}
