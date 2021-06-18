#include "Toggle.h"

AutumnEngine::Toggle::Toggle() { m_CurrentSprite = nullptr; m_DisabledToggle = nullptr; m_EnabledToggle = nullptr; m_ToggleState = State::enabled; }
AutumnEngine::Toggle::Toggle(sf::Texture* disabledTexture, sf::Texture* enabledTexture, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	m_CurrentSprite = new AutumnEngine::Sprite(disabledTexture, "Toggle_Background", position, size, colour, layer);

	m_DisabledToggle = new AutumnEngine::Sprite(disabledTexture, "Toggle_Background", position, size, colour, layer);
	m_EnabledToggle = new AutumnEngine::Sprite(enabledTexture, "Toggle_Handle", position, size, colour, layer);

	SetToggleState(State::disabled);
}
AutumnEngine::Toggle::~Toggle() {}

void AutumnEngine::Toggle::ChangeToggleState()
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
	window->draw(*m_CurrentSprite, m_CurrentSprite->GetRenderState());
}