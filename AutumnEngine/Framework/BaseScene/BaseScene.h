#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Input/Input.h"
#include "../Layers/GUILayer/GUILayer.h"
#include "../AssetManager/AssetManager.h"
#include "../GameState/GameState.h"

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

			void SetGUILayer(AutumnEngine::GUILayer* guiManager) { m_GUILayer = guiManager; }
			AutumnEngine::GUILayer& GetGUILayer() { return *m_GUILayer; }

			void SetAssetManager(AutumnEngine::AssetManager* assetManager) { m_AssetManager = assetManager; }
			AutumnEngine::AssetManager& GetAssetManager() { return *m_AssetManager; }

			void Begin();
			void Begin(sf::Color color);
			void End();

		private:
			AutumnEngine::GUILayer* m_GUILayer;
			AutumnEngine::Input* m_Input;
			AutumnEngine::AssetManager* m_AssetManager;

			int m_SceneIndex;
			std::string m_SceneName;

			sf::RenderWindow* m_Window;

		protected:
			int m_FPS{ 0 };
	};
}