#pragma once
#include "../Sprite/Sprite.h"
#include "../UIComponent/UIComponent.h"

namespace AutumnEngine
{
	class Button : public UIComponent
	{
		enum class m_State { Idle, Hover, Pressed, Inactive };

		public:
			Button();
			Button(sf::Texture* idleTexture, sf::Texture* hoverTexture, sf::Texture* pressedTexture, std::string elementName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer);
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