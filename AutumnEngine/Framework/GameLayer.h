#pragma once
#include "SceneManager.h"
#include "AssetManager.h"
#include "GameState.h"

#include "../Game/Scenes/Main Menu/MainMenu.h"
#include "../Game/Scenes/Test Scene/TestScene.h"
#include "../Game/Scenes/Splashscreen/Splashscreen.h"

namespace AutumnEngine
{
	class GameLayer
	{
		// CONSTRUCTORS AND DESTRUCTORS
		public:
			GameLayer();
			GameLayer(sf::RenderWindow* window);
			~GameLayer();

		// METHOD DEFINITIONS
		public:
			void InitialiseGame();
			void CheckIfGameDirectoriesExist();
			void AddScenesToGame();
			void Update(float deltaTime);

		// GETTERS AND SETTERS
		public:
			AutumnEngine::Input* GetInput() { return m_Input; }

		// GAME CLASS DEFINITIONS
		private:			
			sf::RenderWindow* m_Window;

			AutumnEngine::GameState* m_GameState;
			AutumnEngine::Input* m_Input;
			AutumnEngine::GUILayer* m_GUILayer;
			AutumnEngine::SceneManager* m_SceneManager;
			AutumnEngine::AssetManager* m_AssetManager;

		// SCENE DEFINITIONS
		private:
			AutumnEngine::Splashscreen* m_Splashscreen;
			AutumnEngine::MainMenu* m_MainMenu;
			AutumnEngine::TestScene* m_TestScene;
	};
}