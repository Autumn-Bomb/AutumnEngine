#include "TestScene.h"

AutumnEngine::TestScene::TestScene() { m_FpsFont = nullptr; }
AutumnEngine::TestScene::TestScene(sf::RenderWindow* window)
{
	m_FpsFont = nullptr;
	SetRenderWindow(window);
}
AutumnEngine::TestScene::~TestScene(){}

void AutumnEngine::TestScene::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;

	m_FpsFont = new sf::Font();
	if (!m_FpsFont->loadFromFile({ "Resources/Font/arial.ttf" }))
	{
		std::cout << "Cannot Load Font File!" << std::endl;
	}
}

void AutumnEngine::TestScene::UnloadAssets()
{
	std::cout << "unloading Assets -> " << GetSceneName() << std::endl;
	delete m_FpsFont;
}

void AutumnEngine::TestScene::Awake()
{
	m_FpsText.setFillColor(sf::Color::White);
	m_FpsText.setFont({ *m_FpsFont });
	m_FpsText.setCharacterSize({ 20 });
	m_FpsText.setPosition({ 0, 0 });
	m_FpsText.setString({ "FPS -> " });

	std::cout << "Awake Called -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::HandleInput(float dt)
{
	
}

void AutumnEngine::TestScene::Update(float dt)
{
	m_FPS = 1 / dt;
	m_FpsText.setString({ "FPS: " + std::to_string(m_FPS) });
}

void AutumnEngine::TestScene::Render()
{
	Begin();
	GetRenderWindow()->draw(m_FpsText);
	End();
}