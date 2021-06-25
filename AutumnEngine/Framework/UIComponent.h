#pragma once
#include "Input.h"
#include "Collision.h"

namespace AutumnEngine
{
	class UIComponent
	{
		public:
			virtual void Render(sf::RenderWindow* window) {}
			virtual void HandleCollisions(AutumnEngine::Input input) {}

			void SetRenderingLayer(int layer) { m_Layer = layer; }
			void SetRenderStateTexture(sf::Texture* texture) { m_State->texture = texture; }
			void SetComponentName(std::string componentName) { m_ComponentName = componentName; }

			std::string GetElementName() { return m_ComponentName; }
			int GetRenderingLayer() { return m_Layer; }

			UIComponent GetCurrentUIComponent() { return *this; }

			// Used for Button Detection
			bool GetIsButtonPressed() { return m_IsPressed; }
			void SetIsButtonPressed(bool isPressed) { m_IsPressed = isPressed; }

		private:
			bool m_IsPressed{ false };

			int m_Layer{ 0 };
			std::string m_ComponentName{ "" };
			sf::RenderStates* m_State = nullptr;
	};	
}