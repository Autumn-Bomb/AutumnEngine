#pragma once
#include "Window.h"

namespace AutumnEngine
{
	class Application
	{
		public:
			Application();
			~Application();

			void StartApplication();

		private:
			AutumnEngine::Window m_Window;
	};
}