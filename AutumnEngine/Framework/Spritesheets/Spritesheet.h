#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../GUI/Sprite/Sprite.h"

namespace AutumnEngine
{
	class Spritesheet
	{
			// CONSTRUCTOR AND DESTRUCTOR
		public:
			Spritesheet();
			Spritesheet(sf::Texture* texture);
			~Spritesheet();

			// PUBLIC METHODS FOR USE
		public:
			void LoadSprite(std::string filePath);
			void AddSprite(sf::IntRect spritePosSize, sf::Vector2f position);
			void Batch();
			void Render(sf::RenderWindow* window);

		// CONTAINERS AND HIDDEN VARIABLES
		private:
			sf::RenderTexture m_RenderTexture;
			sf::Texture* m_Texture;
			sf::Sprite m_Sprite;
	};
}