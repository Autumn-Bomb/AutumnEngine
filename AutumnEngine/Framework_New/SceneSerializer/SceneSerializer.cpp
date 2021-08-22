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
}

void AutumnEngine::SceneSerializer::SerializeScene()
{
	std::cout << "Serializing Scene" << std::endl;
}