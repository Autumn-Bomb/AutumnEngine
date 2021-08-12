#include "2DRenderer.h"
#include <iostream> 

AutumnEngine::Renderer::Renderer()
{
	std::cout << "Initialising Renderer!";
}
AutumnEngine::Renderer::~Renderer(){}

void AutumnEngine::Renderer::AddToRenderTexture(sf::Drawable& drawable)
{
	m_RenderTexture.clear(sf::Color::Black);
	std::cout << "Drawing Drawable!";
	m_RenderTexture.draw(drawable);
	m_RenderTexture.display();
	std::cout << "Drawable has been Drawn!";
}