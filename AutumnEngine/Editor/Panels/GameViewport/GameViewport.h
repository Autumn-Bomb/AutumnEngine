#pragma once
#include "../BasePanel/BasePanel.h"
#include "../../../Framework/2DRenderer/2DRenderer.h"

namespace AutumnEngine
{
	class GameViewport : public AutumnEngine::Panel
	{
		public:
			GameViewport();
			~GameViewport();

		public:
			void OnImGuiRender() override;

		public:
			void SetRenderer(AutumnEngine::Renderer& renderer) { m_Renderer = &renderer; }
		
		private:
			AutumnEngine::Renderer* m_Renderer;
	};
}