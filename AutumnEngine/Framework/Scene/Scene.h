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

		// FUNCTIONS USED BY THE SCENE CLASS
		public:
			void OnSceneOpened(AutumnEngine::Hierarchy& SceneHierarchy);
			void OnCreate();
			void OnDestroy();
			void OnActivate();
			void OnDeactivate();
			void OnSceneClosed();

		public:
			void DrawScene();

		// GETTERS AND SETTERS FOR USE BY OTHER CLASSES
		public:
			void SetSceneFilePath(std::filesystem::path sceneFilePath) { m_SceneFilePath = sceneFilePath; }
			std::filesystem::path& GetSceneFilePath() { return m_SceneFilePath; }
			std::string& GetSceneName() { return m_SceneName; }

			AutumnEngine::Entity& GetEntityFromScene(std::string entityName)
			{
				auto pairFound = m_Entities.find(entityName);

				if (pairFound != m_Entities.end())
				{
					return pairFound->second;
				}
			}

			AutumnEngine::Entity& GetAllEntitysFromScene()
			{
				for (auto entity : m_Entities)
				{
					return entity.second;
				}
			}

			std::unordered_map<std::string, AutumnEngine::Entity> GetSceneEntityMap()
			{
				return m_Entities;
			}

		// PRIVATE VARIABLES USED BY THE SCENE CLASS
		private:
			std::string m_SceneName;
			std::filesystem::path m_SceneFilePath;
			std::unordered_map<std::string, AutumnEngine::Entity> m_Entities;

			sf::RenderTexture m_SceneTexture;
	};
}