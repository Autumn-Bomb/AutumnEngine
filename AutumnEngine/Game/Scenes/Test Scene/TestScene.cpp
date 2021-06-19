#include "TestScene.h"

AutumnEngine::TestScene::TestScene() {}
AutumnEngine::TestScene::TestScene(sf::RenderWindow* window, AutumnEngine::Input* input, AutumnEngine::GUI* guiManager)
{
	SetRenderWindow(window);
	SetGUIManager(guiManager);
	SetInput(input);
}
AutumnEngine::TestScene::~TestScene(){}

void AutumnEngine::TestScene::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::UnloadAssets()
{
	std::cout << "unloading Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::Awake()
{
	GetGUIManager().CreateTextElement("arial", "FPS - ", { 0 ,0 }, 22, sf::Color::White);
	GetGUIManager().CreateSpriteUIElement("background", "Background", { 0, 0 }, sf::Vector2f(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height), sf::Color::White, 1);
	std::cout << "Awake Called -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::HandleInput(float dt)
{

}

void AutumnEngine::TestScene::Update(float dt)
{
	static_cast<float>(m_FPS = 1 / dt);
	GetGUIManager().GetTextElement(0).UpdateText("FPS - " + std::to_string(m_FPS));
}

void AutumnEngine::TestScene::Render()
{
	Begin();
	GetRenderWindow()->draw(GetGUIManager().GetSpriteUIElement(0), GetGUIManager().GetSpriteUIElement(0).GetRenderState());
	GetGUIManager().GetTextElement(0).Render(GetRenderWindow());
	End();
}