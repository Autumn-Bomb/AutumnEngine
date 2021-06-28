#pragma once
#include "SceneManager.h"
#include "AssetManager.h"
#include "GameState.h"

#include "../Game/Scenes/Main Menu/MainMenu.h"
#include "../Game/Scenes/Test Scene/TestScene.h"

namespace AutumnEngine
{
	class GameLayer
	{
		public:
			GameLayer();
			GameLayer(sf::RenderWindow* window);
			~GameLayer();

			void InitialiseGame();
			void CheckIfGameDirectoriesExist();
			void AddScenesToGame();

			void Update(float deltaTime);

			void SwitchState(std::string sceneName);

			AutumnEngine::Input* GetInput() { return m_Input; }

		private:			
			AutumnEngine::GameState* m_GameState;
			AutumnEngine::MainMenu* m_MainMenu;
			AutumnEngine::TestScene* m_TestScene;

			sf::RenderWindow* m_Window;

			AutumnEngine::Input* m_Input;
			AutumnEngine::GUILayer* m_GUILayer;
			AutumnEngine::SceneManager* m_SceneManager;
			AutumnEngine::AssetManager* m_AssetManager;
	};
}