#include "MainMenu.h"

AutumnEngine::MainMenu::MainMenu() { m_SceneManager = nullptr; }
AutumnEngine::MainMenu::MainMenu(sf::RenderWindow* window, AutumnEngine::Input* input, AutumnEngine::GUILayer* guiLayer, AutumnEngine::SceneManager* sceneManager)
{
	SetRenderWindow(window);
	SetGUILayer(guiLayer);
	SetInput(input);

	m_SceneManager = sceneManager;
}

AutumnEngine::MainMenu::~MainMenu()
{
	delete m_SceneManager;
	m_SceneManager = nullptr;
}

void AutumnEngine::MainMenu::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::MainMenu::UnloadAssets()
{
	std::cout << "Unloading Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::MainMenu::Awake()
{
	GetGUILayer()->ClearComponents();

	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateSpriteUIElement("background", "Background", { 0, 0 }, { 1920, 1080 }, sf::Color::White, 0));
	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateSpriteUIElement("logo", "Logo", { 835, 200 }, { 250, 250 }, sf::Color::White, 0));
	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateTextElement("arial", "Ping Pong", "MainMenuTitle", { 740, 10 }, 100, sf::Color::White));
	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateTextElement("arial", "Autumn Engine - v1.0.0 - Autumn Bomb LTD 2021", "VersionNumber", { 10, 1045 }, 22, sf::Color::White));
	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateButtonElement("ButtonIdle", "ButtonHover", "ButtonPressed", "MainMenuPlayButton", { 900, 500 }, { 150, 175 }, sf::Color::White, 1));
	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateButtonElement("ExitButtonIdle", "ExitButtonHover", "ExitButtonPressed", "MainMenuExitButton", { 900, 700 }, { 150, 175 }, sf::Color::White, 1));

	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::MainMenu::HandleInput(float dt)
{
	GetGUILayer()->GetUIComponent("MainMenuPlayButton").HandleCollisions(GetInput());
	GetGUILayer()->GetUIComponent("MainMenuExitButton").HandleCollisions(GetInput());
}

void AutumnEngine::MainMenu::Update(float dt)
{

}

void AutumnEngine::MainMenu::Render()
{
	Begin();

	GetGUILayer()->Render(GetRenderWindow());

	End();
}