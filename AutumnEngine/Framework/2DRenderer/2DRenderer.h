#pragma once
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "imgui.h"

namespace AutumnEngine
{
	class Renderer
	{
		public:
			Renderer();
			~Renderer();

		public:
			void Create(const unsigned int x, const unsigned int y, sf::Color colour);
			void Clear(sf::Color color) { m_RenderTexture.clear(color); }
			void Clear() { m_RenderTexture.clear(); }
			void Draw(sf::Drawable& drawable) { m_RenderTexture.draw(drawable); }
			void Display() { m_RenderTexture.display(); }

		public:
			void RenderEntity(sf::Drawable& entity);

		public:
			sf::RenderTexture* GetRenderTexture() { return &m_RenderTexture; }
			unsigned int GetWidth() { return m_RenderTexture.getSize().x; }
			unsigned int GetHeight() { return m_RenderTexture.getSize().y; }

		private:
			sf::RenderStates m_RenderState;
			sf::RenderTexture m_RenderTexture;
			sf::Color m_ClearColour;

			unsigned int m_Width;
			unsigned int m_Height;
	};
}