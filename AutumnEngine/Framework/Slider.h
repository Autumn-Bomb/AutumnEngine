#pragma once

#include "SFML/Graphics.hpp"
#include "Sprite.h"

namespace AutumnEngine
{
	class Slider
	{
		public:
			Slider();
			Slider(sf::Texture* background, sf::Texture* handle, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, const float min, const float max);
			~Slider();

			void Render(sf::RenderWindow* window);

		private:
			AutumnEngine::Sprite m_Background;
			AutumnEngine::Sprite m_Handle;

			float m_Min;
			float m_Max;
	};
}