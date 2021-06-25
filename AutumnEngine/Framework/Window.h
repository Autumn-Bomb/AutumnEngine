#pragma once
#include "SFML/Graphics.hpp"
#include "GameLayer.h"

namespace AutumnEngine
{
	class Window
	{
		public:
			Window();
			Window(unsigned int width, unsigned int height, std::string title, bool vSync, bool fullscreen);
			~Window();

			void SetupWindow(unsigned int width, unsigned int height, std::string title, bool vSync, bool fullscreen);
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