#pragma once
#include "Sprite.h"
#include "UIComponent.h"

namespace AutumnEngine
{
	class Button : public UIComponent
	{
		enum class m_State { Idle, Hover, Pressed, Inactive };

		public:
			Button();
			Button(const sf::Texture* idleTexture, const sf::Texture* hoverTexture, const sf::Texture* pressedTexture, const std::string elementName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer);
			~Button();

			void ChangeButtonState(m_State buttonState);
			
			void OnHover();
			void OnIdle();
			void OnPressed();

			void Render(sf::RenderWindow* window) override;
			void HandleCollisions(AutumnEngine::Input input) override;

			sf::RectangleShape& GetCollisionBox() { return m_CollisionBox; }
			m_State m_ButtonState;

		private:
			sf::RectangleShape m_CollisionBox;

			sf::Vector2f m_Position;
			sf::Vector2f m_Size;

			AutumnEngine::Sprite* m_CurrentSprite;

			AutumnEngine::Sprite m_IdleSprite;
			AutumnEngine::Sprite m_HoverSprite;
			AutumnEngine::Sprite m_PressedSprite;
	};
}