#pragma once
#include "../BasePanel/BasePanel.h"

namespace AutumnEngine
{
	class Profiler : public AutumnEngine::Panel
	{
		public:
			Profiler();
			~Profiler();

		public:
			void CalculateFPSAndFrameTime();
			void OnImGuiRender() override;

		private:
			unsigned int m_FPS;
			float m_FrameTime;
	};
}