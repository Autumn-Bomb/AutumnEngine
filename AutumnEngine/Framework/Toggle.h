#pragma once
#include "Sprite.h"
#include "UIComponent.h"

namespace AutumnEngine
{
	enum class State { disabled, enabled, inactive };

	class Toggle : public UIComponent
	{
		public:
			Toggle();
			Toggle(sf::Texture* disabledTexture, sf::Texture* enabledTexture, 
				sf::Vector2f position,
				sf::Vector2f size, sf::Color colour, int layer);
			~Toggle();

			void SetToggleEnabled(bool enabled);
			void Render(sf::RenderWindow* window) override;
			void HandleCollisions(AutumnEngine::Input input) override;

			State GetToggleState() { return m_ToggleState; }
			bool GetToggleStateBool() { return m_Enabled; }

			sf::RectangleShape* GetCollisionBox() { return &m_CollisionBox; }

		private:
			bool m_Enabled;
			State m_ToggleState;

			sf::RectangleShape m_CollisionBox;
			AutumnEngine::Sprite* m_CurrentSprite;

			AutumnEngine::Sprite* m_DisabledToggle;
			AutumnEngine::Sprite* m_EnabledToggle;
	};
}