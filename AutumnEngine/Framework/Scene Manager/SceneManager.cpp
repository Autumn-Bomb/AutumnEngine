#include "SceneManager.h"

AutumnEngine::SceneManager::SceneManager() {}
AutumnEngine::SceneManager::~SceneManager() {}

void AutumnEngine::SceneManager::LoadScene(AutumnEngine::Scene scene)
{
	m_LoadedScene = scene;
	m_LoadedScene.OnSceneLoaded();
}

void AutumnEngine::SceneManager::Update(float dt)
{
	m_LoadedScene.OnSceneUpdate(dt);
}

void AutumnEngine::SceneManager::DrawScene()
{
	m_LoadedScene.DrawScene();
}

void AutumnEngine::SceneManager::SaveScene()
{
	
}

void AutumnEngine::SceneManager::UnloadScene()
{
	m_LoadedScene.OnSceneUnloaded();
}