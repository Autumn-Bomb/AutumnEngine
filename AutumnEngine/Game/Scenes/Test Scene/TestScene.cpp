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
	m_GUIManager.CreateSliderElement("SliderBackground", "SliderHandle", { 100, 250 }, { 168, 19 }, { 15, 32 }, 0, 100);
	m_GUIManager.CreateSliderElement("SliderBackground", "SliderHandle", { 100, 300 }, { 168, 19 }, { 15, 32 }, 0, 100);

	m_GUIManager.CreateToggleElement("ToggleDeactivated", "ToggleActivated", { 100, 400 }, { 50, 50 }, sf::Color::White, 1);
	m_GUIManager.CreateToggleElement("ToggleDeactivated", "ToggleActivated", { 100, 450 }, { 50, 50 }, sf::Color::White, 1);

	m_GUIManager.CreateButtonElement("ButtonIdle", "ButtonHover", "ButtonPressed", { 400, 400 }, { 150, 50 }, sf::Color::White, 1);
	m_GUIManager.CreateButtonElement("ButtonIdle", "ButtonHover", "ButtonPressed", { 400, 450 }, { 150, 50 }, sf::Color::White, 1);
	m_GUIManager.CreateButtonElement("ButtonIdle", "ButtonHover", "ButtonPressed", { 400, 500 }, { 150, 50 }, sf::Color::White, 1);

	m_GUIManager.GetToggleElement(0).SetToggleEnabled(false);
	m_GUIManager.GetToggleElement(1).SetToggleEnabled(true);

	m_GUIManager.GetSliderElement(0).ChangeValue(100);
	m_GUIManager.GetSliderElement(1).ChangeValue(50);
	m_GUIManager.GetSliderElement(1).ChangeValue(0);

	m_GUIManager.GetButtonElement(0).OnIdle();
	m_GUIManager.GetButtonElement(1).OnHover();
	m_GUIManager.GetButtonElement(2).OnPressed();

	std::cout << "Awake Called -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::HandleInput(float dt)
{
	
}

void AutumnEngine::TestScene::Update(float dt)
{
	static_cast<int>(m_FPS = 1.f / dt);

	m_GUIManager.GetTextElement(0).UpdateText("FPS: " + std::to_string(m_FPS));
}

void AutumnEngine::TestScene::Render()
{
	Begin();

	GetRenderWindow()->draw(m_GUIManager.GetSpriteUIElement(1), m_GUIManager.GetSpriteUIElement(1).GetRenderState());
	GetRenderWindow()->draw(m_GUIManager.GetSpriteUIElement(0), m_GUIManager.GetSpriteUIElement(0).GetRenderState());

	m_GUIManager.GetTextElement(0).Render(GetRenderWindow());

	m_GUIManager.GetSliderElement(0).Render(GetRenderWindow());
	m_GUIManager.GetSliderElement(1).Render(GetRenderWindow());
	m_GUIManager.GetSliderElement(2).Render(GetRenderWindow());

	m_GUIManager.GetToggleElement(0).Render(GetRenderWindow());
	m_GUIManager.GetToggleElement(1).Render(GetRenderWindow());

	m_GUIManager.GetButtonElement(0).Render(GetRenderWindow());
	m_GUIManager.GetButtonElement(1).Render(GetRenderWindow());
	m_GUIManager.GetButtonElement(2).Render(GetRenderWindow());

	End();
}