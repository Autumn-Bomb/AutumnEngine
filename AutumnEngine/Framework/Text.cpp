#include "Text.h"
AutumnEngine::Text::Text() {}
AutumnEngine::Text::Text(const std::string fontName, const std::string text, sf::Vector2f position, const int characterSize, const sf::Color colour)
{
	LoadFont(fontName);

	m_Text.setFont(*m_Font);
	m_Text.setCharacterSize(characterSize);
	m_Text.setPosition(position);
	m_Text.setFillColor(colour);
}
AutumnEngine::Text::~Text() {}

// Creation and Updating of Text Elements
void AutumnEngine::Text::LoadFont(std::string fontName)
{
	m_Font = new sf::Font;
	if (!m_Font->loadFromFile("Resources/Font/" + fontName + ".ttf"))
	{
		std::cout << "Couldn't locate Font named: " << fontName << ".ttf" << std::endl;
	}
}

void AutumnEngine::Text::UpdateText(std::string text)
{
	m_Text.setString(text);
}

void AutumnEngine::Text::Render(sf::RenderWindow* window)
{
	window->draw(m_Text);
}