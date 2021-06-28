#include "GUILayer.h"

AutumnEngine::GUILayer::GUILayer() { m_GUICamera = nullptr; }
AutumnEngine::GUILayer::GUILayer(sf::Vector2f position, sf::Vector2f size)
{
	m_GUICamera = new sf::View(position, size);
}

void AutumnEngine::GUILayer::Awake(){}

void AutumnEngine::GUILayer::Update(float dt)
{
	// used for updating elements
}                                                                      

void AutumnEngine::GUILayer::HandleCollisions(AutumnEngine::Input input)
{
	for (AutumnEngine::UIComponent* components : m_UIElements)
	{
		components->HandleCollisions(input);
	}
}

void AutumnEngine::GUILayer::AddUIComponent(AutumnEngine::UIComponent* uiComponent)
{
	m_UIElements.push_back(uiComponent);
}

AutumnEngine::UIComponent& AutumnEngine::GUILayer::GetUIComponent(std::string componentName)
{
	for (AutumnEngine::UIComponent* component : m_UIElements)
	{
		if (component->GetElementName() == componentName)
		{
			return *component;
		}
	}
}

void AutumnEngine::GUILayer::Render(sf::RenderWindow* window)
{
	window->setView(*m_GUICamera);

	for (AutumnEngine::UIComponent* components : m_UIElements)
	{
		components->Render(window);
	}
}