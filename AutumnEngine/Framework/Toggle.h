#pragma once
#include "Sprite.h"

namespace AutumnEngine
{
	class Toggle
	{
		public:
			enum class State { disabled, enabled, inactive };

			Toggle();
			Toggle(sf::Texture* disabledTexture, sf::Texture* enabledTexture, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer);
			~Toggle();

			void SetToggleState(State state) { m_ToggleState = state; ChangeState(); }
			void ChangeState();

			void Render(sf::RenderWindow* window);

		private:
			State m_ToggleState;

			AutumnEngine::Sprite* m_CurrentSprite;

			AutumnEngine::Sprite* m_DisabledToggle;
			AutumnEngine::Sprite* m_EnabledToggle;
	};
}