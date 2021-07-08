#include "Entity.h"

AutumnEngine::Entity::Entity(){ m_IsAlive = false; m_MovementSpeed = 0.f; }
AutumnEngine::Entity::~Entity() {}
AutumnEngine::Entity::Entity(sf::Texture* spriteTexture, std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
{
	m_IsAlive = true;
	m_MovementSpeed = 0;
}

void AutumnEngine::Entity::Move(int x, int y)
{
	m_Sprite->UpdatePosition(sf::Vector2f(m_Sprite->GetPosition().x + x, m_Sprite->GetPosition().y + y));
}

void AutumnEngine::Entity::Draw(sf::RenderWindow* window)
{
	m_Sprite->Render(window);
}