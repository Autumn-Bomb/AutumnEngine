#include "GameLayer.h"

AutumnEngine::GameLayer::GameLayer()
{ 
	m_Window = nullptr;

	m_Input = nullptr;
	m_AssetManager = nullptr;
	m_SceneManager = nullptr;
	m_GUILayer = nullptr;

	m_MainMenu = nullptr;
	m_TestScene = nullptr;
}
AutumnEngine::GameLayer::GameLayer(sf::RenderWindow* window)
{
	m_Window = window;

	m_Input = nullptr;
	m_AssetManager = nullptr;
	m_SceneManager = nullptr;
	m_GUILayer = nullptr;

	m_MainMenu = nullptr;
	m_TestScene = nullptr;
}
AutumnEngine::GameLayer::~GameLayer(){}

void AutumnEngine::GameLayer::InitialiseGame()
{
	m_Input = new AutumnEngine::Input();
	m_SceneManager = new AutumnEngine::SceneManager();
	m_AssetManager = new AutumnEngine::AssetManager();
	m_GUILayer = new AutumnEngine::GUILayer(sf::Vector2f(m_Window->getSize().x / 2, m_Window->getSize().y / 2), sf::Vector2f(m_Window->getSize().x, m_Window->getSize().y));
	
	CheckIfGameDirectoriesExist();
}

void AutumnEngine::GameLayer::CheckIfGameDirectoriesExist()
{
	m_AssetManager->LoadJSON("init", "EngineInitialiser");
	nlohmann::json json = m_AssetManager->GetJSON("EngineInitialiser");

	for (int line = 0; line < json["ResourcePaths"].size(); line++)
	{
		m_AssetManager->CheckIfDirectoriesExist(json["ResourcePaths"][line]);
	}

	AddScenesToGame();
}

void AutumnEngine::GameLayer::AddScenesToGame()
{
	m_MainMenu = new AutumnEngine::MainMenu(*m_Window, *m_Input, *m_GUILayer, *m_SceneManager, *m_AssetManager);
	m_TestScene = new AutumnEngine::TestScene(*m_Window, *m_Input, *m_GUILayer, *m_AssetManager);

	m_SceneManager->AddScene(0, "Main Menu", m_MainMenu);
	m_SceneManager->AddScene(1, "Test Scene", m_TestScene);

	m_SceneManager->SetDefaultScene("Main Menu");
}

void AutumnEngine::GameLayer::Update(float deltaTime)
{
	m_SceneManager->UpdateScene(deltaTime);
	m_Input->Update();
}

void AutumnEngine::GameLayer::SwitchState(std::string sceneName)
{
	switch (m_GameState->GetGameState())
	{
		case AutumnEngine::GameState::gameState::SPLASHSCREEN: m_SceneManager->ChangeScene("Splashscreen"); break;
		case AutumnEngine::GameState::gameState::MAINMENU: m_SceneManager->ChangeScene("Main Menu"); break;
		case AutumnEngine::GameState::gameState::INGAME: m_SceneManager->ChangeScene("Game Scene"); break;
		case AutumnEngine::GameState::gameState::PAUSED: break;
		case AutumnEngine::GameState::gameState::SETTINGS: break;
		case AutumnEngine::GameState::gameState::QUIT: m_Window->close(); break;
	}
}