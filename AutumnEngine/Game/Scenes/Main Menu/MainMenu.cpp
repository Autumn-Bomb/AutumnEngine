#include "MainMenu.h"

AutumnEngine::MainMenu::MainMenu() {}
AutumnEngine::MainMenu::MainMenu(sf::RenderWindow* window, AutumnEngine::Input* input, AutumnEngine::GUI* guiManager, AutumnEngine::SceneManager* sceneManager)
{
	SetRenderWindow(window);
	SetGUIManager(guiManager);
	SetInput(input);

	m_SceneManager = sceneManager;
}

AutumnEngine::MainMenu::~MainMenu()
{

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
	GetGUIManager().CreateButtonElement("ButtonIdle", "ButtonHover", "ButtonPressed", { 100, 100 }, { 150, 50 }, sf::Color::White, 1);
	GetGUIManager().GetButtonElement(0).OnIdle();

	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::MainMenu::HandleInput(float dt)
{
	if (AutumnEngine::Collision::CheckBoundingBox(GetGUIManager().GetButtonElement(0).GetCollisionBox(), sf::Vector2i(GetInput().GetMouseX(), GetInput().GetMouseY())))
	{
		GetGUIManager().GetButtonElement(0).OnHover();

		if (GetInput().IsLeftMousePressed())
			m_SceneManager->ChangeScene("Test Scene");
			
	}
	else
	{
		GetGUIManager().GetButtonElement(0).OnIdle();
	}
}

void AutumnEngine::MainMenu::Update(float dt)
{

}

void AutumnEngine::MainMenu::Render()
{
	Begin();
	GetGUIManager().GetButtonElement(0).Render(GetRenderWindow());
	End();
}