#include "Button.h"

AutumnEngine::Button::Button() { m_ButtonState = m_State::Idle; m_CurrentSprite = nullptr; }
AutumnEngine::Button::Button(
	
	sf::Texture* idleTexture, sf::Texture* hoverTexture, sf::Texture* pressedTexture, std::string elementName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
{
	m_IdleSprite = AutumnEngine::Sprite(idleTexture, "Button_Idle", position, size, colour, layer);
	m_HoverSprite = AutumnEngine::Sprite(hoverTexture, "Button_Hover", position, size, colour, layer);
	m_PressedSprite = AutumnEngine::Sprite(pressedTexture, "Button_Pressed", position, size, colour, layer);

	m_Position = position;
	m_Size = size;

	m_CollisionBox.setSize(m_Size);
	m_CollisionBox.setPosition(m_Position);

	SetComponentName(elementName);
	OnIdle();
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
			SetIsButtonPressed(false);
			m_CurrentSprite = &m_IdleSprite;
		}
			break;
		case m_State::Hover:
		{
			SetIsButtonPressed(false);
			m_CurrentSprite = &m_HoverSprite;
		}
			break;
		case m_State::Pressed:
		{
			SetIsButtonPressed(true);
			m_CurrentSprite = &m_PressedSprite;
		}
			break;
		case m_State::Inactive:
		{
			m_CurrentSprite = &m_IdleSprite;
		}
			break;
	}
}

void AutumnEngine::Button::HandleCollisions(AutumnEngine::Input input)
{
	sf::Vector2i mousePos = sf::Vector2i(input.GetMouseX(), input.GetMouseY());

	if (AutumnEngine::Collision::CheckBoundingBox(&GetCollisionBox(), mousePos))
	{
		OnHover();

		if (input.IsLeftMouseDown())
			OnPressed();
	}
	else
	{
		OnIdle();
	}
}

void AutumnEngine::Button::Render(sf::RenderWindow* window)
{
	window->draw(*m_CurrentSprite, m_CurrentSprite->GetRenderState());
}