#pragma once
#include "BaseScene.h"

namespace AutumnEngine
{
	class SceneManager
	{
		// CONSTRUCTORS AND DESTRUCTORS
		public:
			SceneManager();
			~SceneManager();

		// METHOD DEFINITIONS
		public:
			void AddScene(int sceneIndex, std::string sceneName, BaseScene* scene);
			void SetDefaultScene(std::string sceneName);
			void UpdateScene(float dt);
			void ChangeScene(std::string sceneName);
			void SwitchState(AutumnEngine::GameState::gameState state);
			void UnloadScene();

		// CONTAINER AND CURRENT SCENE ACCESSOR
		private:
			std::vector<BaseScene*> m_Scenes;
			BaseScene* m_CurrentScene;
	};
}