#pragma once
#include "imgui.h"
#include "../../../Framework_New/2DRenderer/2DRenderer.h"

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
			AutumnEngine::Renderer* m_Renderer;
	};
}