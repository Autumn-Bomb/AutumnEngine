#include "I'mBatman.h"

AutumnEngine::ImBatman::ImBatman() {}
AutumnEngine::ImBatman::ImBatman(sf::Texture* spriteTexture, std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
{
	m_Sprite = new AutumnEngine::Sprite(spriteTexture, name, position, size, colour, layer);
}
AutumnEngine::ImBatman::~ImBatman() {}

void AutumnEngine::ImBatman::Move(int x, int y)
{
	Move(x, y);
}

void AutumnEngine::ImBatman::Render(sf::RenderWindow* window)
{
	Draw(window);
}