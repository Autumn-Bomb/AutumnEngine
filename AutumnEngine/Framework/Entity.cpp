#include "Entity.h"
#include <iostream>

AutumnEngine::Entity::Entity() { m_Transform = nullptr; }
AutumnEngine::Entity::Entity(sf::Texture* spriteTexture, sf::Vector2f position, sf::Vector2f size, int layer)
{
	m_Transform = new sf::Transformable();
	m_Transform->setOrigin(m_Sprite.GetSprite()->getBounds().width / 2, m_Sprite.GetSprite()->getBounds().height / 2);
	m_Sprite = AutumnEngine::Sprite(m_Transform->getTransform(), spriteTexture, position, size, layer);
}
AutumnEngine::Entity::~Entity(){}

void AutumnEngine::Entity::SetPosition(const float x, const float y)
{
	m_Transform->setPosition(x, y);
	m_CollisionBox = sf::FloatRect(m_Transform->getPosition().x, m_Transform->getPosition().y, m_Sprite.GetSpriteSize().x, m_Sprite.GetSpriteSize().y);
	m_Sprite.SetTransform(m_Transform);
}

void AutumnEngine::Entity::SetRotation(const float rotation)
{
	m_Transform->setRotation(rotation);
	m_Sprite.SetTransform(m_Transform);
}
void AutumnEngine::Entity::SetSize(const float width, const float height){}