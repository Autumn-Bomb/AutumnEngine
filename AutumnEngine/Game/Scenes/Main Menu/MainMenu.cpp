#include "MainMenu.h"

AutumnEngine::MainMenu::MainMenu() { m_SceneManager = nullptr; }
AutumnEngine::MainMenu::MainMenu(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiLayer, AutumnEngine::SceneManager& sceneManager, AutumnEngine::AssetManager& assetManager)
{
	SetRenderWindow(&window);
	SetGUILayer(&guiLayer);
	SetInput(&input);

	m_SceneManager = &sceneManager;
	m_AssetManager = &assetManager;
}

AutumnEngine::MainMenu::~MainMenu()
{
	delete m_SceneManager;
	m_SceneManager = nullptr;
}

void AutumnEngine::MainMenu::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;

	m_AssetManager->LoadFont("Resources/Fonts/arial.ttf", "MainFont");

	m_AssetManager->LoadTexture("Resources/Sprites/Textures/background.png", "Background");
	m_AssetManager->LoadTexture("Resources/Sprites/Textures/logo.png", "Logo");

	m_AssetManager->LoadTexture("Resources/Sprites/UI/ButtonIdle.png", "ButtonIdle");
	m_AssetManager->LoadTexture("Resources/Sprites/UI/ButtonHover.png", "ButtonHover");
	m_AssetManager->LoadTexture("Resources/Sprites/UI/ButtonPressed.png", "ButtonPressed");

	m_AssetManager->LoadTexture("Resources/Sprites/UI/ExitButtonIdle.png", "ExitButtonIdle");
	m_AssetManager->LoadTexture("Resources/Sprites/UI/ExitButtonHover.png", "ExitButtonHover");
	m_AssetManager->LoadTexture("Resources/Sprites/UI/ExitButtonPressed.png", "ExitButtonPressed");
	
	std::cout << "Loaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::MainMenu::UnloadAssets()
{
	std::cout << "Unloading Assets -> " << GetSceneName() << std::endl;
	m_AssetManager->ClearAssets();
	std::cout << "Unloaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::MainMenu::Awake()
{
	GetGUILayer().ClearComponents();
	
	GetGUILayer().AddUIComponent(GetGUILayer().CreateSpriteUIElement(&m_AssetManager->GetTexture("Background"), "Background", {0, 0}, {1920, 1080}, sf::Color::White, 0));
	GetGUILayer().AddUIComponent(GetGUILayer().CreateSpriteUIElement(&m_AssetManager->GetTexture("Logo"), "Logo", { 835, 200 }, { 250, 250 }, sf::Color::White, 0));
	GetGUILayer().AddUIComponent(GetGUILayer().CreateTextElement(&m_AssetManager->GetFont("arial"), "MainMenuTitle", "Demo Game", {740, 10}, 100, sf::Color::White));
	GetGUILayer().AddUIComponent(GetGUILayer().CreateTextElement(&m_AssetManager->GetFont("arial"), "VersionNumber", "Autumn Engine - v1.0.0 - Autumn Bomb LTD 2021", { 10, 1045 }, 22, sf::Color::White));
	GetGUILayer().AddUIComponent(GetGUILayer().CreateButtonElement(&m_AssetManager->GetTexture("ButtonIdle"), &m_AssetManager->GetTexture("ButtonHover"), &m_AssetManager->GetTexture("ButtonPressed"), "MainMenuPlayButton", { 900, 500 }, { 150, 175 }, sf::Color::White, 1));
	GetGUILayer().AddUIComponent(GetGUILayer().CreateButtonElement(&m_AssetManager->GetTexture("ExitButtonIdle"), &m_AssetManager->GetTexture("ExitButtonHover"), &m_AssetManager->GetTexture("ExitButtonPressed"), "MainMenuExitButton", { 900, 700 }, { 150, 175 }, sf::Color::White, 1));

	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::MainMenu::HandleInput(float dt)
{
	GetGUILayer().GetUIComponent("MainMenuPlayButton").HandleCollisions(GetInput());
	GetGUILayer().GetUIComponent("MainMenuExitButton").HandleCollisions(GetInput());
}

void AutumnEngine::MainMenu::Update(float dt)
{
	if(GetGUILayer().GetUIComponent("MainMenuPlayButton").GetIsButtonPressed())
	{
		m_SceneManager->SwitchState(AutumnEngine::GameState::gameState::INGAME);
	}
	else
	{
		if (GetGUILayer().GetUIComponent("MainMenuExitButton").GetIsButtonPressed())
		{
			m_SceneManager->SwitchState(AutumnEngine::GameState::gameState::QUIT);
		}
	}
}

void AutumnEngine::MainMenu::Render()
{
	GetGUILayer().Render();
}