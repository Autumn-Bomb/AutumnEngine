#include "../Framework/Sprite.h"

AutumnEngine::Sprite::Sprite() {}
AutumnEngine::Sprite::Sprite(const sf::Texture* spriteTexture, const sf::Vector2f position, const sf::Vector2f size, const int layer)
{
	state = new sf::RenderStates();

	m_Layer = layer;
	m_TextureSize = spriteTexture->getSize();

	// Initialise m_Quad with a PrimitiveType of Quad with 4 Vertices
	m_Quad = sf::VertexArray(sf::PrimitiveType::Quads, 4);

	state->texture = spriteTexture;

	SetColour(sf::Color::White);

	// Initialise Quad with position, size, layer and sprite
	InitialiseQuad(position, size);
}
AutumnEngine::Sprite::~Sprite() {}

void AutumnEngine::Sprite::InitialiseQuad(sf::Vector2f position, sf::Vector2f size)
{
	// Initialises the Quads 4 corners with a position based on the starting x and y and also the specified width and height, also initialises the Texture Coordinates for placing textures on the Quads surface
	m_Quad[0].position = sf::Vector2f(position.x, position.y);
	m_Quad[0].texCoords = sf::Vector2f(0, 0);

	m_Quad[1].position = sf::Vector2f(position.x + size.x, position.y);
	m_Quad[1].texCoords = sf::Vector2f(m_TextureSize.x, 0);

	m_Quad[2].position = sf::Vector2f(position.x + size.x, position.y + size.y);
	m_Quad[2].texCoords = sf::Vector2f(m_TextureSize.x, m_TextureSize.y);

	m_Quad[3].position = sf::Vector2f(position.x, position.y + size.y);
	m_Quad[3].texCoords = sf::Vector2f(0, m_TextureSize.y);
}

// Sets the Quads entire colour - can be used for tinting effects on sprites
void AutumnEngine::Sprite::SetColour(sf::Color colour)
{
	m_Quad[0].color = colour;
	m_Quad[1].color = colour;
	m_Quad[2].color = colour;
	m_Quad[3].color = colour;
}

// DOESN'T NEED TO BE CALLED, SPRITE CAN BE RENDERED WITHOUT CALLING THIS DRAW METHOD
void AutumnEngine::Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Quad, states);
}