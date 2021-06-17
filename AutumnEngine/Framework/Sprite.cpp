#include "../Framework/Sprite.h"

AutumnEngine::Sprite::Sprite() {}
AutumnEngine::Sprite::Sprite(const sf::Texture* spriteTexture, std::string name, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	state = new sf::RenderStates();

	// Initialise m_Quad with a PrimitiveType of Quad with 4 Vertices
	m_Quad = sf::VertexArray(sf::PrimitiveType::Quads, 4);

	m_SpriteName = name;
	m_Layer = layer;
	
	SetTextureSize(spriteTexture->getSize());
	SetPosition(position);
	SetSize(size);
	SetColour(colour);

	state->texture = spriteTexture;

	// Initialise Quad with position, size, layer and sprite
	InitialiseQuad();
}
AutumnEngine::Sprite::~Sprite() {}

void AutumnEngine::Sprite::InitialiseQuad()
{
	// Initialises the Quads 4 corners with a position based on the starting x and y and also the specified width and height, also initialises the Texture Coordinates for placing textures on the Quads surface
	m_Quad[0].position = sf::Vector2f(GetPosition().x, GetPosition().y);
	m_Quad[0].texCoords = sf::Vector2f(0, 0);

	m_Quad[1].position = sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y);
	m_Quad[1].texCoords = sf::Vector2f(GetTextureSize().x, 0);

	m_Quad[2].position = sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y + GetSize().y);
	m_Quad[2].texCoords = sf::Vector2f(GetTextureSize().x, GetTextureSize().y);

	m_Quad[3].position = sf::Vector2f(GetPosition().x, GetPosition().y + GetSize().y);
	m_Quad[3].texCoords = sf::Vector2f(0, GetTextureSize().y);
}

// DOESN'T NEED TO BE CALLED, SPRITE CAN BE RENDERED WITHOUT CALLING THIS DRAW METHOD
void AutumnEngine::Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Quad, states);
}