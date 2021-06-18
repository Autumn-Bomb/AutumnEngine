#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

namespace AutumnEngine
{
	class Text
	{
		public:
			Text();
			Text(const std::string fontName, const std::string text, sf::Vector2f position, const int characterSize, const sf::Color colour);
			~Text();

			void UpdateText(std::string text);
			void Render(sf::RenderWindow* window);

		private:
			void LoadFont(std::string fontName);

			sf::Font* m_Font;
			sf::Text m_Text;	
	};
}