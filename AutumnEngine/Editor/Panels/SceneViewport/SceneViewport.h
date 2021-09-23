#pragma once
#include "../../../Framework/2DRenderer/2DRenderer.h"
#include "../BasePanel/BasePanel.h"

namespace AutumnEngine
{
	class SceneViewport : public AutumnEngine::Panel
	{
		public:
			SceneViewport();
			~SceneViewport();

		public:
			void OnImGuiRender();

		public:
			void SetRenderer(AutumnEngine::Renderer& renderer) { m_Renderer = &renderer; }

		private:
			bool m_RendererCreated;
			AutumnEngine::Renderer* m_Renderer;
	};
}