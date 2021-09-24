#pragma once
#include "../Entities/BaseEntity/Entity.h"
#include "../../../Editor/Panels/Hierarchy/Hierarchy.h"
#include <filesystem>

namespace AutumnEngine
{
	class Scene
	{
		// CONSTRUCTOR AND DESTRUCTOR
		public:
			Scene();
			~Scene();

		public:
			void OnSceneLoaded();
			void OnSceneUpdate(float dt);
			void DrawScene();
			void OnSceneUnloaded();

		// GETTERS AND SETTERS FOR USE BY OTHER CLASSES
		public:
			void SetSceneFilePath(std::filesystem::path sceneFilePath) { m_SceneFilePath = sceneFilePath; }
			std::filesystem::path& GetSceneFilePath() { return m_SceneFilePath; }
			std::string& GetSceneName() { return m_SceneName; }

		// PRIVATE VARIABLES USED BY THE SCENE CLASS
		private:
			std::string m_SceneName;
			std::filesystem::path m_SceneFilePath;
			std::unordered_map<std::string, AutumnEngine::Entity> m_Entities;
	};
}