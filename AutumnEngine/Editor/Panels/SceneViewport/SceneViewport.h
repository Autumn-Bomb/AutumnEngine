#pragma once
#include "../../../Framework/2DRenderer/2DRenderer.h"
#include "imgui.h"
#include "imgui-SFML.h"

namespace AutumnEngine
{
	class SceneViewport
	{
		public:
			SceneViewport();
			~SceneViewport();

		public:
			void ShowSceneViewport();

		public:
			void SetRenderer(AutumnEngine::Renderer& renderer) { m_Renderer = &renderer; }

		private:
			std::unique_ptr<sf::Texture> m_MoveIcon;
			sf::Sprite m_Move;

			std::unique_ptr<sf::Texture> m_CursorIcon;
			sf::Sprite m_Cursor;

			bool m_RendererCreated;
			AutumnEngine::Renderer* m_Renderer;
	};
}