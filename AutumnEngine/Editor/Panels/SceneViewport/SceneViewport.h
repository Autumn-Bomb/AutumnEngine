#pragma once
#include "../../../Framework_New/2DRenderer/2DRenderer.h"
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
			void DrawGrid(int rows, int columns);

		public:
			void SetRenderer(AutumnEngine::Renderer& renderer) { m_Renderer = &renderer; }

		private:
			sf::VertexArray m_Grid;
			bool m_RendererCreated;
			AutumnEngine::Renderer* m_Renderer;
	};
}