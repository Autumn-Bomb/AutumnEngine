#pragma once

#include "SFML/Graphics.hpp"
#include "Sprite.h"

namespace AutumnEngine
{
	class Slider
	{
		public:
			Slider();
			Slider(sf::Texture* background, sf::Texture* handle, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, float min, float max);
			~Slider();

			void Render(sf::RenderWindow* window);
			void ChangeValue(float value);

			sf::Vector2f GetBackgroundPos() { return m_BackgroundPosition; }
			sf::Vector2f GetHandlePosition() { return m_HandlePosition; }

			float GetCurrentValue() { return m_CurrentValue; }

		private:
			sf::Vector2f m_BackgroundPosition;
			sf::Vector2f m_HandlePosition;

			AutumnEngine::Sprite m_Background;
			AutumnEngine::Sprite m_Handle;

			float m_CurrentValue;
			float m_Min;
			float m_Max;
	};
}