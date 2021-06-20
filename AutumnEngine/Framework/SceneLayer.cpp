#include "SceneLayer.h"

AutumnEngine::SceneLayer::SceneLayer(){}
AutumnEngine::SceneLayer::SceneLayer(sf::Vector2f position, sf::Vector2f size)
{
	m_SceneCamera = sf::View(position, size);
}

void AutumnEngine::SceneLayer::Awake()
{

}

void AutumnEngine::SceneLayer::Update(float dt)
{
	m_SceneManager.UpdateScene(dt);
}

void AutumnEngine::SceneLayer::Render(sf::RenderWindow* window)
{
	window->setView(m_SceneCamera);
}