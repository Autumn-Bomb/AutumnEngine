#pragma once
#include "SFML/Graphics.hpp"
#include "Sprite.h"

#include <string>
#include <vector>
#include <iostream>

namespace AutumnEngine
{
	class GUI
	{
		public:
			GUI();
			~GUI();

			// Creation and Updating of Text Elements
			void CreateTextElement(const std::string fontName, const std::string text, sf::Vector2f position, const int fontSize, const sf::Color colour);
			void UpdateTextElement(const int index, std::string text);
			void UpdateTextElement(const int index, int text);
			sf::Text& GetTextElement(const int index) { return m_TextElements[index]; }

			// Creation and Updating of Sprite Elements
			void CreateSpriteUIElement(const std::string textureName, const std::string spriteName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color color, const int layer);
			AutumnEngine::Sprite& GetSpriteUIElement(const int index) { return m_SpriteElements[index]; }

			// Creation and Updating of Button Elements
			void CreateButtonElement(const std::string textureName, const std::string spriteName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color color, const int layer);

			// Creation and Updating of Slider Elements
			// Creation and Updating of Toggle Elements
		private:
			void LoadFont(std::string fontName);

			sf::Font* m_Font;
			std::vector<sf::Text> m_TextElements;
			std::vector<AutumnEngine::Sprite> m_SpriteElements;
	};
}