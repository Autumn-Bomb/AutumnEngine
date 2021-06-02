#pragma once
#include "SFML/Graphics.hpp"

namespace AutumnEngine 
{
	class Sprite : public sf::Drawable
	{
		public:
			Sprite();
			Sprite(sf::Transform transform, sf::Texture* spriteTexture, sf::Vector2f position, sf::Vector2f size, int layer);
			~Sprite();

			void InitialiseQuad(const sf::Vector2f position, const sf::Vector2f size);
			void SetColour(const sf::Color colour);

			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

			sf::VertexArray* GetSprite() {	return &m_Quad; }
			int GetLayer() { return m_Layer; }

			sf::Vector2u GetSpriteSize() { return m_TextureSize; }

			sf::RenderStates& GetRenderState() { return *state; }
			sf::Transform GetTransform() { return state->transform; }

			void SetTransform(sf::Transformable* transform) { state->transform *= transform->getTransform(); }

		private:
			int m_Layer;
			sf::Vector2u m_TextureSize;

			sf::RenderStates* state;
			sf::VertexArray m_Quad;
	};
}