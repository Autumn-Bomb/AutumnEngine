#pragma once
#include "Sprite.h"

namespace AutumnEngine
{
	class Entity
	{
		public:
			Entity();
			Entity(sf::Texture* spriteTexture, sf::Vector2f position, sf::Vector2f size, int layer);
			~Entity();

			void SetPosition(const float x, const float y);
			void SetSize(const float width, const float heigh);
			void SetRotation(const float rotation);

			sf::Vector2f GetPosition() { return m_Transform->getPosition(); }
			float GetRotation() { return m_Transform->getRotation(); }

			AutumnEngine::Sprite& GetSprite() { return m_Sprite; }
			sf::Transformable GetTransform() { return *m_Transform; }

		private:
			sf::Transformable* m_Transform;
			AutumnEngine::Sprite m_Sprite;
	};
}