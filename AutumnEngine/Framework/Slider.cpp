#include "Slider.h"

AutumnEngine::Slider::Slider() { m_Min = 0; m_Max = 0; }
AutumnEngine::Slider::Slider(sf::Texture* background, sf::Texture* handle, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, float min, float max)
{
	m_Background = AutumnEngine::Sprite(background, "Slider_Background", backgroundPosition, backgroundSize, sf::Color::White, 1);
	m_Handle = AutumnEngine::Sprite(handle, "Slider_Handle", { 0, 0 }, handleSize, sf::Color::White, 1);

	m_Handle.SetPosition(sf::Vector2f(m_Background.GetPosition().x + m_Background.GetTextureSize().x, m_Background.GetPosition().y - m_Handle.GetTextureSize().y / 4.5));

	m_BackgroundPosition = backgroundPosition;
	m_HandlePosition = m_Handle.GetPosition();

	m_CollisionBox.setSize(sf::Vector2f(m_Handle.GetTextureSize().x, m_Handle.GetTextureSize().y));
	m_CollisionBox.setPosition(m_HandlePosition);

	m_Max = max;
	m_Min = min;
}
AutumnEngine::Slider::~Slider() {}

void AutumnEngine::Slider::SetValue(float value)
{
	if (value > m_Max)
	{
		value = m_Max;
		m_Handle.SetPosition({ m_Background.GetPosition().x + m_Background.GetSize().x * (value / m_Max), m_Handle.GetPosition().y });
		m_HandlePosition = m_Handle.GetPosition();
	}
	else if (value < m_Min)
	{
		value = m_Min;
		m_Handle.SetPosition({ m_Background.GetPosition().x + m_Background.GetSize().x * (value / m_Min) + m_Handle.GetSize().x, m_Handle.GetPosition().y });
		m_HandlePosition = m_Handle.GetPosition();
	}
	else
	{
		m_Handle.SetPosition({ m_Background.GetPosition().x + m_Background.GetSize().x * (value / m_Max) - m_Handle.GetSize().x, m_Handle.GetPosition().y });
		m_HandlePosition = m_Handle.GetPosition();
	}

	m_CollisionBox.setPosition(m_HandlePosition);
	m_CurrentValue = value;
}

void AutumnEngine::Slider::Render(sf::RenderWindow* window)
{
	window->draw(m_Background, m_Background.GetRenderState());
	window->draw(m_Handle, m_Handle.GetRenderState());
}