#pragma once
#include "SFML/Graphics.hpp"
#include "UIComponent.h"

namespace AutumnEngine
{
	class Sprite : public sf::Drawable, public UIComponent
	{
		public:
			Sprite();
			Sprite(const sf::Texture* spriteTexture, std::string name, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer);
			~Sprite();

			void InitialiseQuad();

			sf::VertexArray* GetSprite() { return &m_Quad; }
			int GetLayer() { return m_Layer; }

			void SetTextureSize(sf::Vector2u textureSize) { m_TextureSize = textureSize; }
			sf::Vector2u GetTextureSize() { return m_TextureSize; }
			sf::RenderStates& GetRenderState() { return *state; }
			void SetPosition(sf::Vector2f position) { m_Position = position; InitialiseQuad(); }
			sf::Vector2f GetPosition() { return m_Position; }
			void SetSize(sf::Vector2f size) { m_Size = size; InitialiseQuad(); }
			sf::Vector2f GetSize() { return m_Size; }

			void Render(sf::RenderWindow* window) override { window->draw(*this, GetRenderState()); }
			void HandleCollisions(AutumnEngine::Input input) override {}

			// Sets the Quads entire colour - can be used for tinting effects on sprites
			void SetColour(sf::Color colour)
			{
				m_Quad[0].color = colour;
				m_Quad[1].color = colour;
				m_Quad[2].color = colour;
				m_Quad[3].color = colour;
			}

		private:
			int m_Layer;

			sf::Vector2u m_TextureSize;
			sf::Vector2f m_Size;
			sf::Vector2f m_Position;
			sf::RenderStates* state;
			sf::VertexArray m_Quad;

			std::string m_SpriteName;

			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}