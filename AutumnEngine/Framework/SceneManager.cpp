#include "SceneManager.h"

AutumnEngine::SceneManager::SceneManager()
{
	m_CurrentScene = nullptr;
}
AutumnEngine::SceneManager::~SceneManager(){}

// Adds a new scene to the vector list for use by the game
void AutumnEngine::SceneManager::AddScene(int sceneIndex, std::string sceneName, BaseScene* scene)
{
	scene->SetSceneName(sceneName);
	scene->SetSceneIndex(sceneIndex);
	m_Scenes.push_back(scene);

	std::cout << scene->GetSceneName() << " -> " << "Added with Index: " << scene->GetSceneIndex() << std::endl;
}

void AutumnEngine::SceneManager::SetDefaultScene(std::string sceneName)
{
	for (BaseScene* scene : m_Scenes)
	{
		if (scene->GetSceneName() == sceneName)
		{
			m_CurrentScene = scene;
			std::cout << m_CurrentScene->GetSceneName() << " -> " << "Default Scene" << std::endl;
			m_CurrentScene->LoadAssets();
			m_CurrentScene->Awake();
			return;
		}
	}
}

// Used to unload all assets from the previous scene, load all assets in for the new scene and change the current scene
void AutumnEngine::SceneManager::ChangeScene(std::string sceneName)
{
	for (BaseScene* scene : m_Scenes)
	{
		if (scene->GetSceneName() == sceneName)
		{
			if (m_CurrentScene != nullptr)
			{
				m_CurrentScene->UnloadAssets();
				std::cout << m_CurrentScene->GetSceneName() << " -> " << "Deleted" << std::endl;
				delete m_CurrentScene;
				m_CurrentScene = nullptr;
			}
			
			m_CurrentScene = scene;
			std::cout << m_CurrentScene->GetSceneName() << " -> " << "Changed" << std::endl;
			m_CurrentScene->LoadAssets();
			m_CurrentScene->Awake();
			return;
		}
		else
		{
			std::cout << m_CurrentScene->GetSceneName() << " -> " << "Ignored" << std::endl;
		}
	}
}

// Unloads all assets related to the current scene and deletes the scene from memory
void AutumnEngine::SceneManager::UnloadScene()
{
	m_CurrentScene->UnloadAssets();
	delete m_CurrentScene;
	m_CurrentScene = nullptr;

	std::cout << m_CurrentScene->GetSceneName() << " -> " << "Unloaded" << std::endl;
}

// Used to update all relevant methods needed for the current scene, called while the window is open passing in DeltaTime
void AutumnEngine::SceneManager::UpdateScene(float dt)
{
	if (m_CurrentScene == nullptr)
		return;

	m_CurrentScene->HandleInput(dt);
	m_CurrentScene->Update(dt);
	m_CurrentScene->Render();
}

// Used to switch the games current state
void AutumnEngine::SceneManager::SwitchState(AutumnEngine::GameState::gameState gameState)
{
	switch (gameState)
	{
		case AutumnEngine::GameState::gameState::SPLASHSCREEN: ChangeScene("Splash Screen"); break;
		case AutumnEngine::GameState::gameState::MAINMENU: ChangeScene("Main Menu"); break;
		case AutumnEngine::GameState::gameState::INGAME: ChangeScene("Game Scene"); break;
		case AutumnEngine::GameState::gameState::PAUSED: break;
		case AutumnEngine::GameState::gameState::SETTINGS: ChangeScene("Settings"); break;
		case AutumnEngine::GameState::gameState::QUIT: break;
	}
}