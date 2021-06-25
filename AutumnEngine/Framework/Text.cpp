#include "Text.h"

AutumnEngine::Text::Text() { m_Text = nullptr; }
AutumnEngine::Text::Text(sf::Font* font, std::string textElementName, std::string text, sf::Vector2f position, int characterSize, sf::Color colour)
{
	m_Text = new sf::Text();
	
	SetComponentName(textElementName);

	m_Text->setFont(*font);
	m_Text->setCharacterSize(characterSize);
	m_Text->setPosition(position);
	m_Text->setFillColor(colour);
	m_Text->setString(text);
}
AutumnEngine::Text::~Text() {}

void AutumnEngine::Text::HandleCollisions(AutumnEngine::Input input) {}

void AutumnEngine::Text::UpdateText(std::string text)
{
	m_Text->setString(text);
}

void AutumnEngine::Text::Render(sf::RenderWindow* window)
{
	window->draw(*m_Text);
}