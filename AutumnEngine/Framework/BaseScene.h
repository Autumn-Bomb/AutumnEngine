#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.h"
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

			void Begin();
			void Begin(sf::Color color);
			void End();

		private:
			int m_SceneIndex;
			std::string m_SceneName;

			sf::RenderWindow* m_Window;

		protected:
			std::vector<Entity> m_Entities;
			float m_FPS{ 0 };
	};
}