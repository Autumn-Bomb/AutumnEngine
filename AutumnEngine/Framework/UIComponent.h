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

		private:
			int m_Layer;
			std::string m_ComponentName;
			sf::RenderStates* m_State;
	};	
}