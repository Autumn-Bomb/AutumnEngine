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
			Text(const std::string fontName, const std::string text, sf::Vector2f position, const int characterSize, const sf::Color colour);
			~Text();

			void UpdateText(std::string text);
			void Render(sf::RenderWindow* window) override;
			void HandleCollisions(AutumnEngine::Input input) override;

		private:
			void LoadFont(std::string fontName);

			sf::Font* m_Font;
			sf::Text* m_Text;	
	};
}