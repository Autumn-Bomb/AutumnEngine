#include "Toggle.h"

AutumnEngine::Toggle::Toggle() { m_CurrentSprite = nullptr; m_DisabledToggle = nullptr; m_EnabledToggle = nullptr; }
AutumnEngine::Toggle::Toggle(sf::Texture* disabledTexture, sf::Texture* enabledTexture, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	m_DisabledToggle = new AutumnEngine::Sprite(disabledTexture, "Toggle_Background", position, size, colour, layer);
	m_EnabledToggle = new AutumnEngine::Sprite(enabledTexture, "Toggle_Handle", position, size, colour, layer);

	m_CollisionBox.setSize(size);
	m_CollisionBox.setPosition(position);
}
AutumnEngine::Toggle::~Toggle() {}

void AutumnEngine::Toggle::SetToggleEnabled(bool enabled)
{
	if (enabled)
	{
		m_ToggleState = State::enabled;
		m_CurrentSprite = m_EnabledToggle;
	}
	else
	{
		m_ToggleState = State::disabled;
		m_CurrentSprite = m_DisabledToggle;
	}
}


void AutumnEngine::Toggle::Render(sf::RenderWindow* window)
{
	window->draw(*m_CurrentSprite, m_CurrentSprite->GetRenderState());
}