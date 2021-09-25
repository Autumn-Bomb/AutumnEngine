#include "2DRenderer.h"
#include <iostream> 

AutumnEngine::Renderer::Renderer()
{
	std::cout << "Initialising Renderer!";
	m_Width = 0;
	m_Height = 0;
}
AutumnEngine::Renderer::~Renderer(){}

void AutumnEngine::Renderer::Create(const unsigned int width, const unsigned int height, sf::Color colour)
{
	m_ClearColour = colour;

	std::cout << "\nCreating RenderTexture!\n";
	m_RenderTexture.create(width, height);
	m_Width = width;
	m_Height = height;
	m_RenderTexture.clear(colour);
	std::cout << "\nCreated RenderTexture!\n";
}

void AutumnEngine::Renderer::RenderEntity(sf::Drawable& entity)
{
	//Clear(); // Can also pass a colour
	Draw(entity);
	Display();
}