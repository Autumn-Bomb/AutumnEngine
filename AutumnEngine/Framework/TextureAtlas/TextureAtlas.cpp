#include "TextureAtlas.h"

AutumnEngine::TextureAtlas::TextureAtlas() { m_Texture = nullptr; m_Sprite = nullptr; }
AutumnEngine::TextureAtlas::TextureAtlas(sf::Texture* texture)
{
	// Initialise the vector and both the texture and sprite instances
	m_Sprites = std::vector<sf::Sprite*>();

	m_Sprite = nullptr;
	m_Texture = texture;
}
AutumnEngine::TextureAtlas::~TextureAtlas() {}

void AutumnEngine::TextureAtlas::AddSprite(sf::IntRect spritePosSize, sf::Vector2f position)
{
	// Creates a new instance of m_Sprite passing in the Atlas texture and the position and size of sprite located on the texture, sets its position and then pushes it into the vector
	m_Sprite = new sf::Sprite(*m_Texture, spritePosSize);
	m_Sprite->setPosition(position);
	m_Sprites.push_back(m_Sprite);
}

void AutumnEngine::TextureAtlas::Render(sf::RenderWindow* window)
{
	// Loops through each sprite stored in the m_Sprites vector and draws them to the window
	for (sf::Sprite* sprite : m_Sprites)
	{
		window->draw(*sprite);
	}
}