#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
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
			void LoadTexture(std::string filePath);
			void AddTexture(sf::IntRect spritePosSize, sf::Vector2f position);
			void Batch();
			void Render(sf::RenderWindow* window);

		// CONTAINERS AND HIDDEN VARIABLES
		private:
			sf::RenderTexture m_RenderTexture;
			sf::Texture* m_Texture;
			sf::Sprite m_Sprite;
	};
}