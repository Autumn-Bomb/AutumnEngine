#include "AssetManager.h"

AutumnEngine::AssetManager::AssetManager() {}
AutumnEngine::AssetManager::~AssetManager() {}

void AutumnEngine::AssetManager::LoadTexture(const char* textureName)
{
	m_Texture->loadFromFile(m_TexturePath + textureName);
	m_LoadedTextures.emplace(textureName, m_Texture);
}