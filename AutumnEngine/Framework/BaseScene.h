#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Input.h"
#include "GUI.h"

#include <iostream>

namespace AutumnEngine
{
	class BaseScene
	{
		public:
			BaseScene();
			~BaseScene();

			virtual void HandleInput(float dt);
			virtual void Update(float dt);
			virtual void Render();

			virtual void LoadAssets();
			virtual void UnloadAssets();

			virtual void Awake();

			void SetRenderWindow(sf::RenderWindow* window) { m_Window = window; }
			sf::RenderWindow* GetRenderWindow() { return m_Window; }

			void SetSceneIndex(int sceneIndex) { m_SceneIndex = sceneIndex; }
			int GetSceneIndex() { return m_SceneIndex; }

			void SetSceneName(std::string sceneName) { m_SceneName = sceneName; }
			std::string GetSceneName() { return m_SceneName; }

			void SetInput(AutumnEngine::Input* input) { m_Input = input; }
			AutumnEngine::Input& GetInput() { return *m_Input; }

			void SetGUIManager(AutumnEngine::GUI* guiManager) { m_GUIManager = guiManager; }
			AutumnEngine::GUI& GetGUIManager() { return *m_GUIManager; }

			/*void SetSceneManager(AutumnEngine::SceneManager* sceneManager) { m_SceneManager = sceneManager; }
			AutumnEngine::SceneManager& GetSceneManager() { return *m_SceneManager; }*/

			void Begin();
			void Begin(sf::Color color);
			void End();

		private:
			//AutumnEngine::SceneManager* m_SceneManager;
			AutumnEngine::GUI* m_GUIManager;
			AutumnEngine::Input* m_Input;

			int m_SceneIndex;
			std::string m_SceneName;

			sf::RenderWindow* m_Window;

		protected:
			int m_FPS{ 0 };
	};
}