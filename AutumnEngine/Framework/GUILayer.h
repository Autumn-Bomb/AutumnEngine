#pragma once
#include "UIComponent.h"
#include "GUI.h"

namespace AutumnEngine
{
	class GUILayer
	{
			// CONSTRUCTORS
			public:
				GUILayer();
				GUILayer(sf::Vector2f position, sf::Vector2f size);
		
			// METHOD DEFINITIONS
			public:
				void Awake();
				void Update(float dt);
				void HandleCollisions(AutumnEngine::Input input);
				void Render(sf::RenderWindow* window);
				void AddUIComponent(AutumnEngine::UIComponent* uiComponent);
				void ClearComponents() { m_UIElements.clear(); }

			// GETTERS
			public:
				AutumnEngine::UIComponent& GetUIComponent(std::string componentName);

			// METHOD DEFINITIONS FOR CREATING UI ELEMENTS
			public:
				AutumnEngine::Text* CreateTextElement(sf::Font* font, std::string componentName, std::string text, sf::Vector2f position, int fontSize, sf::Color colour)
				{
					return m_GUIManager.CreateTextElement(font, componentName, text, position, fontSize, colour);
				}

				AutumnEngine::Sprite* CreateSpriteUIElement(sf::Texture* t_Texture, std::string spriteName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
				{
					return m_GUIManager.CreateSpriteUIElement(t_Texture, spriteName, position, size, colour, layer);
				}
				AutumnEngine::Sprite* CreateSpriteUIElement(sf::Texture* t_Texture, std::string spriteName, sf::Vector2f position, sf::Vector2f size, int r, int g, int b, int a, int layer)
				{
					return m_GUIManager.CreateSpriteUIElement(t_Texture, spriteName, position, size, sf::Color(r, g, b, a), layer);
				}

				AutumnEngine::Button* CreateButtonElement(sf::Texture* buttonIdle, sf::Texture* buttonHover, sf::Texture* buttonPressed, std::string componentName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer) 
				{
					return m_GUIManager.CreateButtonElement(buttonIdle, buttonHover, buttonPressed, componentName, position, size, colour, layer);
				}
				AutumnEngine::Slider* CreateSliderElement(std::string sliderBackgroundName, std::string sliderHandleName, std::string componentName, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, float min, float max, int layer)
				{
					return m_GUIManager.CreateSliderElement(sliderBackgroundName, sliderHandleName, componentName, backgroundPosition, backgroundSize, handleSize, min, max, layer);
				}
				AutumnEngine::Toggle* CreateToggleElement(std::string toggleActiveSpriteName, std::string toggleDeactiveSpriteName, std::string componentName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
				{
					return m_GUIManager.CreateToggleElement(toggleActiveSpriteName, toggleDeactiveSpriteName, componentName, position, size, colour, layer);
				}

			// CONTAINER FOR UI ELEMENTS
			private:
				std::vector<UIComponent*> m_UIElements;

			// VARIABLE DEFINITIONS
			private:
				sf::View* m_GUICamera;
				AutumnEngine::GUI m_GUIManager;
	};
}