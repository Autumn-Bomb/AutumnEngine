#include "SceneSerializer.h"

AutumnEngine::SceneSerializer::SceneSerializer() {}
AutumnEngine::SceneSerializer::~SceneSerializer() {}

void AutumnEngine::SceneSerializer::CreateScene(std::filesystem::path scenePath)
{
	m_CurrentScene.SetSceneFilePath(scenePath);
	std::cout << "Created a new Scene with the path: " << scenePath << std::endl;
}

void AutumnEngine::SceneSerializer::DeserializeScene()
{
	std::cout << "Deserializing Scene" << std::endl;
	std::ifstream sceneData (m_CurrentScene.GetSceneFilePath());
	sceneData >> m_SceneData;

	for (int line = 0; line < m_SceneData["Entities"].size(); line++)
	{
		std::cout << "Entity Name: " << m_SceneData["Entities"][line]["m_Name"] << std::endl;
		std::cout << "Entity Tag: " << m_SceneData["Entities"][line]["m_Tag"] << std::endl;
		std::cout << "Entity Layer: " << m_SceneData["Entities"][line]["m_Layer"] << std::endl;
		std::cout << "Entity ID: " << m_SceneData["Entities"][line]["m_ID"] << std::endl;
		std::cout << "Entity Active State: " << m_SceneData["Entities"][line]["m_IsActive"] << std::endl;
		std::cout << "Entity Component IDs: " << m_SceneData["Entities"][line]["m_Components"] << std::endl;
	}
}

void AutumnEngine::SceneSerializer::SerializeScene()
{
	std::cout << "Serializing Scene" << std::endl;
}