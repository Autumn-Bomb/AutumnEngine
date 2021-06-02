#include "TestScene.h"

AutumnEngine::TestScene::TestScene() { m_FpsFont = nullptr; }
AutumnEngine::TestScene::TestScene(sf::RenderWindow* window)
{
	SetRenderWindow(window);
}

AutumnEngine::TestScene::~TestScene()
{

}

void AutumnEngine::TestScene::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;

	m_FpsFont = new sf::Font();
	if (!m_FpsFont->loadFromFile({ "Resources/Font/arial.ttf" }))
	{
		std::cout << "Cannot Load Font File!" << std::endl;
	}

	m_SpriteTexture = new sf::Texture();
	if (!m_SpriteTexture->loadFromFile("Resources/Sprites/penguin.png"))
	{
		std::cout << "Cannot Load Texture!" << std::endl;
	}
}

void AutumnEngine::TestScene::UnloadAssets()
{
	std::cout << "unloading Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::Awake()
{
	for (int i = 0; i < 3000; ++i)
	{
		sf::Vector2f randomPos = sf::Vector2f(rand() % 100 + 1, rand() % GetRenderWindow()->getSize().y + 1);

		AutumnEngine::Entity m_Entity = AutumnEngine::Entity(m_SpriteTexture, randomPos, { 128, 128 }, i);
		m_Entities.push_back(m_Entity);
	}

	m_FpsText.setFont({ *m_FpsFont });
	m_FpsText.setFillColor(sf::Color::White);
	m_FpsText.setCharacterSize({ 20 });
	m_FpsText.setPosition({ 0, 0 });
	m_FpsText.setString({ "FPS -> " });

	AutumnEngine::BubbleSort::SortSpriteLayers(m_Entities, m_Entities.size());
	std::cout << "Awake Called -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::HandleInput(float dt)
{

}

void AutumnEngine::TestScene::Update(float dt)
{
	m_FPS = 1.f / dt;
	m_FpsText.setString({ "FPS: " + std::to_string(m_FPS) });

	//m_Entity.SetRotation(m_Entity.GetRotation() + 100 * dt);
	for (AutumnEngine::Entity entity : m_Entities)
	{
		entity.SetPosition(entity.GetPosition().x + 10 * dt, entity.GetPosition().y);
	}
}

void AutumnEngine::TestScene::Render()
{
	Begin();

	GetRenderWindow()->draw(m_FpsText);
	for (AutumnEngine::Entity entity : m_Entities)
	{
		GetRenderWindow()->draw(entity.GetSprite(), entity.GetSprite().GetRenderState());
	}

	End();
}