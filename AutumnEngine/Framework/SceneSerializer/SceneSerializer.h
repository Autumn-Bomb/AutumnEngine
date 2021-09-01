#pragma once
#include "../Scene/Scene.h"
#include "../../Json/json.hpp"

#include <fstream>
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
			nlohmann::json& GetSceneData() { return m_SceneData; }
		
		private:
			nlohmann::json m_SceneData;
			AutumnEngine::Scene m_CurrentScene;
	};
}