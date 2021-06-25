#include "Toggle.h"

AutumnEngine::Toggle::Toggle() { m_CurrentSprite = nullptr; m_DisabledToggle = nullptr; m_EnabledToggle = nullptr; m_Enabled = true; m_ToggleState = State::enabled; }
AutumnEngine::Toggle::Toggle(sf::Texture* disabledTexture, sf::Texture* enabledTexture, 
	
	sf::Vector2f position,
	sf::Vector2f size, sf::Color colour, int layer)
{
	m_DisabledToggle = new AutumnEngine::Sprite(disabledTexture, "Toggle_Background", position, size, colour, layer);
	m_EnabledToggle = new AutumnEngine::Sprite(enabledTexture, "Toggle_Handle", position, size, colour, layer);

	m_CollisionBox.setSize(size);
	m_CollisionBox.setPosition(position);

	SetToggleEnabled(true);
}
AutumnEngine::Toggle::~Toggle() {}

void AutumnEngine::Toggle::SetToggleEnabled(bool enabled)
{
	if (enabled)
	{
		m_ToggleState = State::enabled;
		m_Enabled = true;
		m_CurrentSprite = m_EnabledToggle;
	}
	else
	{
		m_ToggleState = State::disabled;
		m_Enabled = false;
		m_CurrentSprite = m_DisabledToggle;
	}
}

void AutumnEngine::Toggle::HandleCollisions(AutumnEngine::Input input)
{
	sf::Vector2i mousePos = sf::Vector2i(input.GetMouseX(), input.GetMouseY());

	if (AutumnEngine::Collision::CheckBoundingBox(GetCollisionBox(), mousePos))
	{
		if (input.IsLeftMouseDown())
		{
			SetToggleEnabled(!GetToggleStateBool());
			input.SetLeftMouse(AutumnEngine::Input::MouseState::UP);
		}
	}
}

void AutumnEngine::Toggle::Render(sf::RenderWindow* window)
{
	window->draw(*m_CurrentSprite, m_CurrentSprite->GetRenderState());
}