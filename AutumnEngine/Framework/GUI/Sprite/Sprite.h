#pragma once
#include "SFML/Graphics.hpp"
#include "../UIComponent/UIComponent.h"

namespace AutumnEngine
{
	class Sprite : public sf::Drawable, public UIComponent
	{
		public:
			Sprite();
			Sprite(sf::Texture* spriteTexture, std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer);
			~Sprite();

			void InitialiseQuad();

			void SetSprite(sf::Texture* texture) { GetRenderState().texture = texture; }
			sf::VertexArray* GetSprite() { return &m_Quad; }
			int GetLayer() { return m_Layer; }

			void SetLayer(int layer) { m_Layer = layer; }

			void SetTextureSize(sf::Vector2u textureSize) { m_TextureSize = textureSize; }
			sf::Vector2u GetTextureSize() { return m_TextureSize; }

			sf::RenderStates& GetRenderState() { return *m_RenderState; }

			void SetPosition(sf::Vector2f position) { m_Position = position; InitialiseQuad(); }
			void UpdatePosition(sf::Vector2f position) { m_RenderState->transform.translate(position); }

			sf::Vector2f GetPosition() { return m_Position; }
			void SetSize(sf::Vector2f size) { m_Size = size; InitialiseQuad(); }
			sf::Vector2f GetSize() { return m_Size; }

			void Render(sf::RenderWindow* window) override { window->draw(*this, GetRenderState()); }
			void HandleCollisions(AutumnEngine::Input input) override {}

			// Sets the Quads entire colour - can be used for tinting effects on sprites
			void SetColour(sf::Color colour)
			{
				for (size_t vertex = 0; vertex < m_Quad.getVertexCount(); ++vertex)
				{
					m_Quad[vertex].color = colour;
				}
			}

			// Sets the Quads entire colour with alpha for opacity - can be used for tinting effects on sprites
			void SetColour(int r, int g, int b, int a)
			{
				for (size_t vertex = 0; vertex < m_Quad.getVertexCount(); ++vertex)
				{
					m_Quad[vertex].color = sf::Color(r, g, b, a);
				}
			}

		private:
			int m_Layer;

			sf::Vector2u m_TextureSize;
			sf::Vector2f m_Size;
			sf::Vector2f m_Position;
			sf::RenderStates* m_RenderState;
			sf::VertexArray m_Quad;

			std::string m_SpriteName;

			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}