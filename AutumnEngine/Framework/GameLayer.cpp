#include "GameLayer.h"

AutumnEngine::GameLayer::GameLayer() {}
AutumnEngine::GameLayer::GameLayer(sf::RenderWindow* window)
{
	m_Window = window;

	m_Input = nullptr;
	m_AssetManager = nullptr;
	m_SceneManager = nullptr;
	m_GUILayer = nullptr;
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
	m_AssetManager->CheckIfDirectoriesExist("Resources");
	m_AssetManager->CheckIfDirectoriesExist("Resources/Sprites/UI");
	m_AssetManager->CheckIfDirectoriesExist("Resources/Sounds");
	m_AssetManager->CheckIfDirectoriesExist("Resources/Fonts");

	m_AssetManager->CheckIfDirectoriesExist("Resources/JSON");
	m_AssetManager->CheckIfDirectoriesExist("Resources/JSON/TileMaps");

	AddScenesToGame();
}

void AutumnEngine::GameLayer::AddScenesToGame()
{
	m_MainMenu = new AutumnEngine::MainMenu(*m_Window, *m_Input, *m_GUILayer, *m_SceneManager);
	m_TestScene = new AutumnEngine::TestScene(*m_Window, *m_Input, *m_GUILayer);

	m_SceneManager->AddScene(0, "Main Menu", m_MainMenu);
	m_SceneManager->AddScene(1, "Test Scene", m_TestScene);

	m_SceneManager->SetDefaultScene("Main Menu");
}

void AutumnEngine::GameLayer::Update(float deltaTime)
{
	m_SceneManager->UpdateScene(deltaTime);
	m_Input->Update();
}