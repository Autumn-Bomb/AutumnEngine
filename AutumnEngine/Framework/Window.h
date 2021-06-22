#pragma once
#include "SFML/Graphics.hpp"
#include "GameLayer.h"

namespace AutumnEngine
{
	class Window
	{
		public:
			Window();
			Window(const unsigned int width, const unsigned int height, const char* title, const bool vSync, const bool fullscreen);
			~Window();

			void SetupWindow(const unsigned int width, const unsigned int height, const char* title, const bool vSync, const bool fullscreen);
			void InitialiseGameLayer();
			void HandleWindowEvents();
			void RunWindow();

		private:
			AutumnEngine::GameLayer m_GameLayer;

			sf::Clock m_Clock;
			float m_DeltaTime;

			sf::RenderWindow* m_Window;
			sf::Event m_Event;
	};
}