#include "TextureAtlas.h"
#include <iostream>

AutumnEngine::TextureAtlas::TextureAtlas() { m_Texture = nullptr; m_Sprite = nullptr; m_RenderTexture = nullptr; }
AutumnEngine::TextureAtlas::TextureAtlas(sf::Texture* texture)
{
	// Initialise the vector and both the texture and sprite instances
	m_Sprites = std::vector<sf::Sprite*>();
	m_RenderTexture = new sf::RenderTexture();

	m_Sprite = nullptr;
	m_Texture = texture;

	// Initialise the RenderTexture to the Screen size
	m_RenderTexture->create(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
}
AutumnEngine::TextureAtlas::~TextureAtlas() { }

void AutumnEngine::TextureAtlas::AddSprite(sf::IntRect spritePosSize, sf::Vector2f position)
{
	// Creates a new instance of m_Sprite passing in the Atlas texture and the position and size of sprite located on the texture, sets its position and then pushes it into the vector
	sf::Sprite* sprite = new sf::Sprite(*m_Texture, spritePosSize);
	sprite->setPosition(position);
	m_RenderTexture->draw(*sprite);
	m_RenderTexture->display();
}

void AutumnEngine::TextureAtlas::Batch()
{
	// Takes all sprites from the Render Texture and combines them into one, giving the sprite its texture
	m_Sprite = new sf::Sprite(m_RenderTexture->getTexture());
	std::cout << "Sprites Batched!" << std::endl;
}

void AutumnEngine::TextureAtlas::Render(sf::RenderWindow* window)
{
	// Renders the finished RenderTexture to the current Window
	window->draw(*m_Sprite);
}