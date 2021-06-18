#pragma once
#include "Sprite.h"

namespace AutumnEngine
{
	enum class State { disabled, enabled, inactive };

	class Toggle
	{
		public:
			Toggle();
			Toggle(sf::Texture* disabledTexture, sf::Texture* enabledTexture, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer);
			~Toggle();

			void SetToggleEnabled(bool enabled);
			void Render(sf::RenderWindow* window);

			State GetToggleState() { return m_ToggleState; }

		private:
			State m_ToggleState;

			AutumnEngine::Sprite* m_CurrentSprite;

			AutumnEngine::Sprite* m_DisabledToggle;
			AutumnEngine::Sprite* m_EnabledToggle;
	};
}