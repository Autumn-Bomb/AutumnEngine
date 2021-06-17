#include "Toggle.h"

AutumnEngine::Toggle::Toggle() {}
AutumnEngine::Toggle::Toggle(sf::Texture* disabledTexture, sf::Texture* enabledTexture, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	m_CurrentSprite = new AutumnEngine::Sprite(disabledTexture, "Toggle_Background", position, size, colour, layer);

	m_DisabledToggle = new AutumnEngine::Sprite(disabledTexture, "Toggle_Background", position, size, colour, layer);
	m_EnabledToggle = new AutumnEngine::Sprite(enabledTexture, "Toggle_Handle", position, size, colour, layer);

	SetToggleState(State::enabled);
}
AutumnEngine::Toggle::~Toggle() {}

void AutumnEngine::Toggle::ChangeState()
{
	switch (m_ToggleState)
	{
		case State::inactive:
		{

		}
			break;
		case State::disabled:
		{
			m_CurrentSprite = m_DisabledToggle;
		}
			break;
		case State::enabled:
		{
			m_CurrentSprite = m_EnabledToggle;
		}
		break;
	}
}

void AutumnEngine::Toggle::Render(sf::RenderWindow* window)
{
	window->draw(*m_CurrentSprite);
}