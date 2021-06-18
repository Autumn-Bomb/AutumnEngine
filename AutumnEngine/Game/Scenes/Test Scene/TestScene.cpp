#include "TestScene.h"

AutumnEngine::TestScene::TestScene() {}
AutumnEngine::TestScene::TestScene(sf::RenderWindow* window)
{
	SetRenderWindow(window);
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
	m_GUIManager.CreateTextElement("arial", "FPS: ", { 315, 10 }, 22, sf::Color::White);

	m_GUIManager.CreateSpriteUIElement("healthbar", "HealthBar", { 5, 10 }, { 300, 50 }, sf::Color::White, 1);
	m_GUIManager.CreateSpriteUIElement("background", "Background", { 0, 0 }, { 1920, 1080 }, sf::Color::White, 1);

	m_GUIManager.CreateSliderElement("SliderBackground", "SliderHandle", { 100, 200 }, { 168, 19 }, { 15, 32 }, 0, 100);
	m_GUIManager.CreateToggleElement("ToggleDeactivated", "ToggleActivated", { 100, 400 }, { 50, 50 }, sf::Color::White, 1);

	std::cout << "Slider X: " << m_GUIManager.GetSliderElement(0).GetBackgroundPos().x;

	std::cout << "Awake Called -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::HandleInput(float dt)
{
	
}

void AutumnEngine::TestScene::Update(float dt)
{
	static_cast<int>(m_FPS = 1.f / dt);

	m_GUIManager.UpdateTextElement(0, "FPS: " + std::to_string(m_FPS));
}

void AutumnEngine::TestScene::Render()
{
	Begin();

	GetRenderWindow()->draw(m_GUIManager.GetSpriteUIElement(1), m_GUIManager.GetSpriteUIElement(1).GetRenderState());
	GetRenderWindow()->draw(m_GUIManager.GetSpriteUIElement(0), m_GUIManager.GetSpriteUIElement(0).GetRenderState());
	
	m_GUIManager.GetTextElement(0).Render(GetRenderWindow());
	m_GUIManager.GetSliderElement(0).Render(GetRenderWindow());
	m_GUIManager.GetToggleElement(0).Render(GetRenderWindow());

	End();
}