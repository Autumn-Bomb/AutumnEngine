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
			Window(const unsigned int width, const unsigned int height, const char* title, const bool vSync, const bool fullscreen);
			~Window();

			void SetupWindow(const unsigned int width, const unsigned int height, const char* title, const bool vSync, const bool fullscreen);
			void InitialiseGame();
			void HandleWindowEvents();
			void RunWindow();

		private:
			AutumnEngine::Input* m_Input;
			AutumnEngine::GUI* m_GUIManager;
			AutumnEngine::SceneManager* m_SceneManager;

			sf::Clock m_Clock;
			float m_DeltaTime;

			sf::RenderWindow* m_Window;
			sf::Event m_Event;

			TestScene* m_TestScene;
			MainMenu* m_MainMenu;
	};
}