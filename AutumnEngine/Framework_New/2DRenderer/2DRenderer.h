#pragma once
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace AutumnEngine
{
	class Renderer
	{
		public:
			Renderer();
			~Renderer();

		public:
			void AddToRenderTexture(sf::Drawable& drawable);

		public:
			sf::RenderTexture& GetRenderTexture() { return m_RenderTexture; }

		private:
			sf::RenderTexture m_RenderTexture;
	};
}