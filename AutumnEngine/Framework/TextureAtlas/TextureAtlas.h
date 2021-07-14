#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace AutumnEngine
{
	class TextureAtlas
	{
		// CONSTRUCTOR AND DESTRUCTOR
		public:
			TextureAtlas();
			TextureAtlas(sf::Texture* texture);
			~TextureAtlas();

		// PUBLIC METHODS FOR USE
		public:
			void Render(sf::RenderWindow* window);
			void AddSprite(sf::IntRect spritePosSize, sf::Vector2f position);

		// CONTAINERS AND HIDDEN VARIABLES
		private:
			std::vector<sf::Sprite*> m_Sprites;
			sf::Texture* m_Texture;
			sf::Sprite* m_Sprite;
	};
}