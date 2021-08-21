#pragma once
#include "../Entities/BaseEntity/Entity.h"
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
			void AddEntityToScene(AutumnEngine::Entity& entity);
			void RemoveEntityFromScene(AutumnEngine::Entity& entity);
	
			void DrawScene(sf::RenderTexture& renderTexture);

		// GETTERS AND SETTERS FOR USE BY OTHER CLASSES
		public:
			void SetSceneFilePath(std::filesystem::path sceneFilePath) { m_SceneFilePath = sceneFilePath; }
			AutumnEngine::Entity& GetEntityFromScene(std::string entityName)
			{
				auto pairFound = m_Entities.find(entityName);

				if (pairFound != m_Entities.end())
				{
					return pairFound->second;
				}
			}

		// PRIVATE VARIABLES USED BY THE SCENE CLASS
		private:
			std::filesystem::path m_SceneFilePath;
			std::unordered_map<std::string, AutumnEngine::Entity> m_Entities;
	};
}