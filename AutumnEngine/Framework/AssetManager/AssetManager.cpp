#include "AssetManager.h"

AutumnEngine::AssetManager::AssetManager()
{ 
	m_Texture = nullptr; 
}
AutumnEngine::AssetManager::~AssetManager() {}

void AutumnEngine::AssetManager::LoadTexture(const char* textureName)
{
	m_Texture = new sf::Texture();

	m_Texture->loadFromFile(m_TexturePath + textureName);
	m_LoadedTextures[textureName] = *m_Texture;
}