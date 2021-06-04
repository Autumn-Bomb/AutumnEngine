#pragma once
#include "SFML/Graphics.hpp"
#include "SceneManager.h"

#include "../Game/Scenes/Test Scene/TestScene.h"
#include "../Game/Scenes/Main Menu/MainMenu.h"

namespace AutumnEngine
{
	class Window
	{
		public:
			Window();
			Window(const unsigned int width, const unsigned int height, const char* title, const bool vSync);
			~Window();

			void SetupWindow(const unsigned int width, const unsigned int height, const char* title, const bool vSync);
			void InitialiseGame();
			void HandleWindowEvents();
			void RunWindow();

		private:
			sf::Clock m_Clock;
			float m_DeltaTime;

			sf::RenderWindow* m_Window;
			sf::Event m_Event;

			SceneManager m_SceneManager;
			TestScene* m_TestScene;
			MainMenu* m_MainMenu;
	};
}