#pragma once
#include "Sprite.h"

namespace AutumnEngine
{
	class Button
	{
		enum class m_State { Idle, Hover, Pressed, Inactive };

		public:
			Button();
			Button(sf::Texture* idleTexture, sf::Texture* hoverTexter, sf::Texture* pressedTexture, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer);
			~Button();

			void ChangeButtonState(m_State buttonState);
			
			void OnHover();
			void OnIdle();
			void OnPressed();

			void Render(sf::RenderWindow* window);

			m_State m_ButtonState;

		private:
			sf::Vector2f m_Position;
			sf::Vector2f m_Size;

			AutumnEngine::Sprite* m_CurrentSprite;

			AutumnEngine::Sprite m_Idle;
			AutumnEngine::Sprite m_Hover;
			AutumnEngine::Sprite m_Pressed;
	};
}