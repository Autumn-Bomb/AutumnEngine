#include "AssetManager.h"

AutumnEngine::AssetManager::AssetManager() {}
AutumnEngine::AssetManager::~AssetManager() {}

void AutumnEngine::AssetManager::LoadTexture(std::string textureName, std::string resourceName, SpriteType spriteType, ImageFormat imageFormat)
{
	m_NewTexture = new sf::Texture();

	switch (spriteType)
	{
		case SpriteType::Sprite:
		{
			if (imageFormat == ImageFormat::PNG)
			{
				if (!m_NewTexture->loadFromFile("Resources/Sprites/" + textureName + ".png"))
				{
					std::cout << "Couldn't locate: Resources/Sprites/" << textureName << ".png" << std::endl;
				}

				m_LoadedTextures[resourceName] = m_NewTexture;
				m_LoadedTextures.try_emplace(resourceName, m_NewTexture);

				std::cout << "Key : " << m_LoadedTextures.at(resourceName) << std::endl;
			}
			else if (imageFormat == ImageFormat::JPG)
			{
				if (!m_NewTexture->loadFromFile("Resources/Sprites/" + textureName + ".jpg"))
				{
					std::cout << "Couldn't locate: Resources/Sprites/" << textureName << ".jpg" << std::endl;
				}

				m_LoadedTextures[resourceName] = m_NewTexture;
				m_LoadedTextures.try_emplace(resourceName, m_NewTexture);
			}
		}
			break;
		case SpriteType::Logo:
		{

		}
			break;
		case SpriteType::UI:
		{

		}
		break;
	}
}

sf::Texture& AutumnEngine::AssetManager::GetTexture(std::string fileName)
{
	auto pairFound = m_LoadedTextures.find(fileName);

	if (pairFound != m_LoadedTextures.end())
	{
		return *pairFound->second;
	}
	else
	{
		std::cout << "Resource: " << fileName << " doesn't exist in Asset Manager, searching for file now" << std::endl;
		auto texture = m_LoadedTextures[fileName];
		texture->loadFromFile("Resources/Sprites/Textures/" + fileName + ".png");
		return *texture;
	}
}

void AutumnEngine::AssetManager::LoadSound(std::string soundName, SoundType soundType)
{

}

void AutumnEngine::AssetManager::LoadTileMapJson(std::string fileName)
{
	std::ifstream filePath(fileName); // create a new ifStream called "filePath" and load in the file specified with "spriteSheetCoordsPath"
	filePath >> m_TileMapFile; // copy all contents of the loaded file into the JSON
}

void AutumnEngine::AssetManager::CheckIfDirectoriesExist(std::string folderPath)
{
	if (std::filesystem::exists(folderPath))
	{
		std::cout << "Folder Path: " << folderPath << " exists!" << std::endl;
	}
	else
	{
		std::cout << "Folder Path: " << folderPath << " doesn't exist!" << std::endl;
		std::filesystem::create_directory(folderPath);
		std::cout << "Created: " << folderPath << std::endl;
	}
}