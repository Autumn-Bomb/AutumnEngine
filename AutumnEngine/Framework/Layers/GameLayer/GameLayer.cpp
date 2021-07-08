#include "GameLayer.h"

AutumnEngine::GameLayer::GameLayer()
{ 
	m_Window = nullptr;

	m_Input = nullptr;
	m_AssetManager = nullptr;
	m_SceneManager = nullptr;
	m_GUILayer = nullptr;
	m_GameState = nullptr;

	m_Splashscreen = nullptr;
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
	m_GameState = nullptr;

	m_Splashscreen = nullptr;
	m_MainMenu = nullptr;
	m_TestScene = nullptr;
}
AutumnEngine::GameLayer::~GameLayer(){}

void AutumnEngine::GameLayer::InitialiseGame()
{
	m_Input = new AutumnEngine::Input();
	m_SceneManager = new AutumnEngine::SceneManager();
	m_AssetManager = new AutumnEngine::AssetManager();
	m_GUILayer = new AutumnEngine::GUILayer(sf::Vector2f(static_cast<float>(m_Window->getSize().x / 2), static_cast<float>(m_Window->getSize().y / 2)), sf::Vector2f(static_cast<float>(m_Window->getSize().x), static_cast<float>(m_Window->getSize().y)));
	
	CheckIfGameDirectoriesExist();
}

void AutumnEngine::GameLayer::CheckIfGameDirectoriesExist()
{
	m_AssetManager->LoadJSON("Resources/JSON/init.json", "EngineInitialiser");
	nlohmann::json json = m_AssetManager->GetJSON("EngineInitialiser");

	for (int line = 0; line < json["ResourcePaths"].size(); line++)
	{
		m_AssetManager->CheckIfDirectoriesExist(json["ResourcePaths"][line]);
	}

	AddScenesToGame();
}

void AutumnEngine::GameLayer::AddScenesToGame()
{
	m_Splashscreen = new AutumnEngine::Splashscreen(*m_Window, *m_Input, *m_GUILayer, *m_AssetManager, *m_SceneManager);
	m_MainMenu = new AutumnEngine::MainMenu(*m_Window, *m_Input, *m_GUILayer, *m_SceneManager, *m_AssetManager);
	m_TestScene = new AutumnEngine::TestScene(*m_Window, *m_Input, *m_GUILayer, *m_AssetManager);

	m_SceneManager->AddScene(0, "Splash Screen", m_Splashscreen);
	m_SceneManager->AddScene(1, "Main Menu", m_MainMenu);
	m_SceneManager->AddScene(2, "Game Scene", m_TestScene);

	m_SceneManager->SetDefaultScene("Splash Screen");
}

void AutumnEngine::GameLayer::Update(float deltaTime)
{
	m_SceneManager->UpdateScene(deltaTime);
	m_Input->Update();
}