#include "Slider.h"

AutumnEngine::Slider::Slider() { m_Min = 0; m_Max = 0; }
AutumnEngine::Slider::Slider(sf::Texture* background, sf::Texture* handle, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, const float min, const float max)
{
	m_Background = AutumnEngine::Sprite(background, "Slider_Background", backgroundPosition, backgroundSize, sf::Color::White, 1);
	m_Handle = AutumnEngine::Sprite(handle, "Slider_Handle", { 0, 0 }, handleSize, sf::Color::White, 1);
	
	m_Handle.SetPosition(sf::Vector2f(m_Background.GetPosition().x + m_Background.GetTextureSize().x / 2, m_Background.GetPosition().y - m_Handle.GetTextureSize().y / 4.5));

	m_Min = min;
	m_Max = max;
}
AutumnEngine::Slider::~Slider() {}

void AutumnEngine::Slider::Render(sf::RenderWindow* window)
{
	window->draw(m_Background);
	window->draw(m_Handle);
}