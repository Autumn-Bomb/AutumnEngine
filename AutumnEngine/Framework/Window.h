#pragma once
#include "GameLayer.h"

namespace AutumnEngine
{
	class Window
	{
		// CONSTRUCTORS AND DESTRUCTOR
		public:
			Window();
			Window(unsigned int width, unsigned int height, std::string title, bool vSync, bool fullscreen);
			~Window();

		// FUNCTION DEFINITIONS
		public:
			void SetupWindow(unsigned int width, unsigned int height, std::string title, bool vSync, bool fullscreen);
			void InitialiseGameLayer();
			void HandleWindowEvents();
			void RunWindow();

		// VARIABLES
		private:
			float m_DeltaTime;

		// INSTANCE VARIABLES
		private:
			AutumnEngine::GameLayer m_GameLayer;

			sf::Clock m_Clock;
			sf::Event m_Event;
			sf::RenderWindow* m_Window;
	};
}