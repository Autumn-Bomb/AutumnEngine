#include "AssetManager.h"

AutumnEngine::AssetManager::AssetManager() { m_NewTexture = nullptr; }
AutumnEngine::AssetManager::~AssetManager() {}

void AutumnEngine::AssetManager::LoadTexture(std::string textureName, std::string resourceName, SpriteType spriteType, ImageFormat imageFormat)
{
	m_NewTexture = new sf::Texture();

	switch (spriteType)
	{
		case SpriteType::Sprite:
		{
			m_FilePath = "Resources/Sprites/";
		}
			break;
		case SpriteType::Texture:
		{
			m_FilePath = "Resources/Sprites/Textures/";
		}
			break;
		case SpriteType::Logo:
		{
			m_FilePath = "Resources/Sprites/Logo/";
		}
			break;
		case SpriteType::UI:
		{			
			m_FilePath = "Resources/Sprites/UI/";
		}
			break;
		case SpriteType::TextureAtlas:
		{
			m_FilePath = "Resources/Sprites/TextureAtlases/";
		}
			break;
		case SpriteType::SpriteSheet:
		{
			m_FilePath = "Resources/Sprites/SpriteSheets/";
		}
			break;
	}

	if (imageFormat == ImageFormat::PNG)
	{
		m_FileExtension = ".png";
	}
	else if (imageFormat == ImageFormat::JPG)
	{
		m_FileExtension = ".jpg";
	}

	if (!m_NewTexture->loadFromFile(m_FilePath + textureName + m_FileExtension))
	{
		std::cout << "Couldn't locate: " << m_FilePath + textureName + m_FileExtension << std::endl;
	}

	m_LoadedTextures[resourceName] = m_NewTexture;
	m_LoadedTextures.try_emplace(resourceName, m_NewTexture);
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
		sf::Texture* newTexture = new sf::Texture();

		std::cout << "Resource: " << fileName << " doesn't exist in Asset Manager, searching for file now" << std::endl;
		newTexture->loadFromFile(m_FilePath + fileName + m_FileExtension);
		m_LoadedTextures[fileName] = m_NewTexture;
		m_LoadedTextures.try_emplace(fileName, m_NewTexture);

		return *newTexture;
	}
}

void AutumnEngine::AssetManager::LoadSound(std::string soundName, SoundType soundType)
{

}

void AutumnEngine::AssetManager::LoadTileMapJson(std::string fileName)
{
	std::ifstream filePath("Resources/JSON/TileMaps/" + fileName + ".json"); // create a new ifStream called "filePath" and load in the json file specified
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