#include "MainMenu.h"

AutumnEngine::MainMenu::MainMenu() {}
AutumnEngine::MainMenu::MainMenu(sf::RenderWindow* window)
{
	SetRenderWindow(window);
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
	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::MainMenu::HandleInput(float dt)
{

}

void AutumnEngine::MainMenu::Update(float dt)
{

}

void AutumnEngine::MainMenu::Render()
{
	Begin(sf::Color::White);

	End();
}