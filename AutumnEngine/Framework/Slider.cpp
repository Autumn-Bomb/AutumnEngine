#include "Slider.h"

AutumnEngine::Slider::Slider() { m_Min = 0; m_Max = 0; m_CurrentValue = 100; }
AutumnEngine::Slider::Slider(sf::Texture* background, sf::Texture* handle, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, float min, float max, int layer)
{
	m_Background = AutumnEngine::Sprite(background, "Slider_Background", backgroundPosition, backgroundSize, sf::Color::White, 1);
	m_Handle = AutumnEngine::Sprite(handle, "Slider_Handle", { 0, 0 }, handleSize, sf::Color::White, 1);

	m_Handle.SetPosition(sf::Vector2f(m_Background.GetPosition().x + m_Background.GetTextureSize().x, m_Background.GetPosition().y - m_Handle.GetTextureSize().y / 4.5));

	m_CollisionBoxBackground.setSize(sf::Vector2f(m_Background.GetTextureSize().x, m_Background.GetTextureSize().y));
	m_CollisionBoxBackground.setPosition(GetBackgroundPosition());

	m_CollisionBoxHandle.setSize(sf::Vector2f(m_Handle.GetTextureSize().x, m_Handle.GetTextureSize().y));
	m_CollisionBoxHandle.setPosition(GetHandlePosition());

	m_Max = max;
	m_Min = min;
}
AutumnEngine::Slider::~Slider() {}

void AutumnEngine::Slider::SetValue(float value)
{
	
}

void AutumnEngine::Slider::HandleCollisions(AutumnEngine::Input input)
{

}

void AutumnEngine::Slider::Render(sf::RenderWindow* window)
{
	window->draw(m_Background, m_Background.GetRenderState());
	window->draw(m_Handle, m_Handle.GetRenderState());
}