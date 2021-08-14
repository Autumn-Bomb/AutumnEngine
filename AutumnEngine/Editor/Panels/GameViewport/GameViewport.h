#pragma once
#include "imgui.h"
#include "imgui-SFML.h"

#include "../../../Framework_New/2DRenderer/2DRenderer.h"

namespace AutumnEngine
{
	class GameViewport
	{
		public:
			GameViewport();
			~GameViewport();

		public:
			void ShowGameViewport();

		public:
			void SetRenderer(AutumnEngine::Renderer& renderer) { m_Renderer = &renderer; }
		
		private:
			AutumnEngine::Renderer* m_Renderer;
	};
}