#include "2DRenderer.h"
#include <iostream> 

AutumnEngine::Renderer::Renderer()
{
	std::cout << "Initialising Renderer!";
}
AutumnEngine::Renderer::~Renderer(){}

void AutumnEngine::Renderer::Create(const unsigned int width, const unsigned int height)
{
	if (m_RenderTexture == nullptr)
	{
		std::cout << "\nCreating RenderTexture!\n";
		m_RenderTexture = new sf::RenderTexture();
		m_RenderTexture->create(width, height);
		this->width = width;
		this->height = height;
		std::cout << "\nCreated RenderTexture!\n";
	}
	else
	{
		delete m_RenderTexture;
		m_RenderTexture = nullptr;

		std::cout << "\nRecreating RenderTexture!\n";
		m_RenderTexture = new sf::RenderTexture();
		m_RenderTexture->create(width, height);
		m_RenderTexture->clear(sf::Color::Transparent);
		std::cout << "\nRecreated RenderTexture!\n";
	}
}

void AutumnEngine::Renderer::AddToRenderTexture(sf::Drawable& drawable)
{
	Create(this->width, this->height);
	std::cout << "\nDrawing Drawable!\n";
	m_RenderTexture->draw(drawable);
	std::cout << "Drawable has been Drawn!\n";
	Display();
}

void AutumnEngine::Renderer::Display()
{
	m_RenderTexture->display();
	std::cout << "Displaying RenderTexture\n";
}

void AutumnEngine::Renderer::Clear(sf::Color color)
{
	m_RenderTexture->clear(color);
}

void AutumnEngine::Renderer::Clear()
{
	m_RenderTexture->clear();
}