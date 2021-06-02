#pragma once
#include "BaseScene.h"
#include <iostream>

namespace AutumnEngine
{
	class SceneManager
	{
		public:
			SceneManager();
			~SceneManager();

			void ChangeScene(std::string sceneName);

			void AddScene(int sceneIndex, std::string sceneName, BaseScene* scene);
			void UpdateScene(float dt);

		private:
			std::vector<BaseScene*> m_Scenes;
			BaseScene* m_CurrentScene;
	};
}