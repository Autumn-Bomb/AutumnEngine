#include "2DRenderer.h"
#include <iostream> 

AutumnEngine::Renderer::Renderer()
{
	std::cout << "Initialising Renderer!";
}
AutumnEngine::Renderer::~Renderer(){}

void AutumnEngine::Renderer::Create(const unsigned int width, const unsigned int height)
{
	std::cout << "\nCreating RenderTexture!\n";
	m_RenderTexture.create(width, height);
	this->width = width;
	this->height = height;
	m_RenderTexture.clear(sf::Color::White);
	std::cout << "\nCreated RenderTexture!\n";
}

void AutumnEngine::Renderer::AddToRenderTexture(sf::Drawable& drawable)
{
	std::cout << "\nDrawing Drawable!\n";
	m_RenderTexture.clear(sf::Color::White);
	m_RenderTexture.draw(drawable);
	m_RenderTexture.display();

	std::cout << "Drawable has been Drawn!\n";
}

void AutumnEngine::Renderer::RenderScene()
{
	// TODO: Add the ability to add all entities in a scene to a list and draw them to the FBO
}

void AutumnEngine::Renderer::Clear(sf::Color color)
{
	m_RenderTexture.clear(color);
}

void AutumnEngine::Renderer::Clear()
{
	m_RenderTexture.clear();
}