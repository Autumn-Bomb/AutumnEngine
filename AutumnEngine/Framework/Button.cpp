#include "Button.h"

AutumnEngine::Button::Button(){}
AutumnEngine::Button::Button(sf::Texture* idleTexture, sf::Texture* hoverTexture, sf::Texture* pressedTexture, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	m_Idle = AutumnEngine::Sprite(idleTexture, "Button_Idle", position, size, colour, layer);
	m_Hover = AutumnEngine::Sprite(hoverTexture, "Button_Hover", position, size, colour, layer);
	m_Pressed = AutumnEngine::Sprite(pressedTexture, "Button_Pressed", position, size, colour, layer);

	m_Position = position;
	m_Size = size;
}
AutumnEngine::Button::~Button(){}

void AutumnEngine::Button::OnIdle()
{
	ChangeButtonState(m_State::Idle);
}

void AutumnEngine::Button::OnHover()
{
	ChangeButtonState(m_State::Hover);
}

void AutumnEngine::Button::OnPressed()
{
	ChangeButtonState(m_State::Pressed);
}

void AutumnEngine::Button::ChangeButtonState(m_State buttonState)
{
	switch (buttonState)
	{
		case m_State::Idle:
		{
			m_CurrentSprite = &m_Idle;
		}
			break;
		case m_State::Hover:
		{
			m_CurrentSprite = &m_Hover;
		}
			break;
		case m_State::Pressed:
		{
			m_CurrentSprite = &m_Pressed;
		}
			break;
		case m_State::Inactive:
		{
			m_CurrentSprite = &m_Idle;
		}
			break;
	}
}

void AutumnEngine::Button::Render(sf::RenderWindow* window)
{
	window->draw(*m_CurrentSprite, m_CurrentSprite->GetRenderState());
}