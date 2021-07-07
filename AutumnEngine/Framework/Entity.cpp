#include "Entity.h"

AutumnEngine::Entity::Entity() { m_IsAlive = false; m_MovementSpeed = 0.f; }
AutumnEngine::Entity::~Entity() {}
AutumnEngine::Entity::Entity(sf::Texture* spriteTexture, std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
{
	m_Sprite = AutumnEngine::Sprite(spriteTexture, name, position, size, colour, layer);
}

void AutumnEngine::Entity::Move(int x, int y)
{
	m_Sprite.SetPosition(sf::Vector2f(x, y));
}

void AutumnEngine::Entity::Render(sf::RenderWindow* window)
{
	window->draw(m_Sprite);
}