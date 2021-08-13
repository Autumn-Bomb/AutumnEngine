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

			void Create(const unsigned int x, const unsigned int y);
			void Display();
			void Clear(sf::Color color);
			void Clear();

		public:
			unsigned int width;
			unsigned int height;

			sf::RenderTexture* GetRenderTexture() { return m_RenderTexture; }
			unsigned int GetWidth() { return m_RenderTexture->getSize().x; }
			unsigned int GetHeight() { return m_RenderTexture->getSize().y; }

		private:
			sf::RenderTexture* m_RenderTexture;
	};
}