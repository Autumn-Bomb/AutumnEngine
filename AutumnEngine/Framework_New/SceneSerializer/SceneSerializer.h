#pragma once
#include "../Scene/Scene.h"
#include <iostream>

namespace AutumnEngine
{
	class SceneSerializer
	{
		public:
			SceneSerializer();
			~SceneSerializer();

		public:
			void SerializeScene();
			void DeserializeScene();

			void CreateScene(std::filesystem::path scenePath);

		public:
			AutumnEngine::Scene& GetCurrentLoadedScene() { return m_CurrentScene; }

		private:
			AutumnEngine::Scene m_CurrentScene;
	};
}