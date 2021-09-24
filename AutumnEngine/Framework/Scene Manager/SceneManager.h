#pragma once
#include "../Scene/Scene.h"

namespace AutumnEngine
{
	class SceneManager
	{
		public:
			SceneManager();
			~SceneManager();

		public:
			void LoadScene(AutumnEngine::Scene scene);
			void UnloadScene();
			void Update(float dt);

			void SaveScene();

			void DrawScene();

		private:
			AutumnEngine::Scene m_LoadedScene;
	};
}