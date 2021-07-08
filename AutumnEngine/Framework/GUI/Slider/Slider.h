#pragma once

#include "SFML/Graphics.hpp"
#include "../UIComponent/UIComponent.h"
#include "../Sprite/Sprite.h"

namespace AutumnEngine
{
	class Slider : public UIComponent
	{
		public:
			Slider();
			Slider(sf::Texture* background, sf::Texture* handle, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, float min, float max, int layer);
			~Slider();

			void Render(sf::RenderWindow* window) override;
			void HandleCollisions(AutumnEngine::Input input) override;

			void SetValue(float value);

			sf::Vector2f GetBackgroundPosition() { return m_Background.GetPosition(); }
			sf::Vector2f GetHandlePosition() { return m_Handle.GetPosition(); }

			float GetCurrentValue() { return m_CurrentValue; }

			sf::RectangleShape* GetHandleCollisionBox() { return &m_CollisionBoxHandle; }
			sf::RectangleShape* GetBackgroundCollisionBox() { return &m_CollisionBoxBackground; }

			sf::Vector2f GetMinAndMax() { return sf::Vector2f(m_Min, m_Max); }

		private:
			sf::RectangleShape m_CollisionBoxHandle;
			sf::RectangleShape m_CollisionBoxBackground;

			AutumnEngine::Sprite m_Background;
			AutumnEngine::Sprite m_Handle;

			float m_CurrentValue;
			float m_Min;
			float m_Max;
	};
}