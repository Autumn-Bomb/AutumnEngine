#pragma once

#include "SFML/Graphics.hpp"
#include "UIComponent.h"
#include "GUI.h"
#include "Bubblesort.h"

namespace AutumnEngine
{
	class GUILayer
	{
		public:
			GUILayer();
			GUILayer(sf::Vector2f position, sf::Vector2f size);

			void Awake();
			void Update(float dt);
			void HandleCollisions(AutumnEngine::Input input);
			void Render(sf::RenderWindow* window);

			void AddUIComponent(AutumnEngine::UIComponent* uiComponent);
			AutumnEngine::UIComponent* GetUIComponent(std::string componentName);

			void ClearComponents() { m_UIElements.clear(); }

			AutumnEngine::GUI GetGUIManager() { return m_GUIManager; }

			private:
				std::vector<UIComponent*> m_UIElements;

				sf::View* m_GUICamera;
				AutumnEngine::GUI m_GUIManager;
	};
}