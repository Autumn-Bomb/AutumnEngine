#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "UIComponent.h"

namespace AutumnEngine
{
	class Text : public UIComponent
	{
		public:
			Text();
			Text(sf::Font* font, std::string textElementName, std::string text, sf::Vector2f position, int characterSize, sf::Color colour);
			~Text();

			void UpdateText(std::string text);
			void Render(sf::RenderWindow* window) override;
			void HandleCollisions(AutumnEngine::Input input) override;

		private:
			sf::Text* m_Text;
	};
}