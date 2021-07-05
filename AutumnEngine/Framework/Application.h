#pragma once
#include "Window.h"

namespace AutumnEngine
{
	class Application
	{
		// CONSTRUCTORS AND DESTRUCTORS
		public:
			Application();
			~Application();

		// METHOD DEFINITIONS
		public:
			void StartApplication();

		// WINDOW DEFINITION
		private:
			AutumnEngine::Window m_Window;
	};
}