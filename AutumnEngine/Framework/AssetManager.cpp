#include "AssetManager.h"

AutumnEngine::AssetManager::AssetManager() {}
AutumnEngine::AssetManager::~AssetManager() {}

void AutumnEngine::AssetManager::LoadTexture(std::string textureName, std::string resourceName, SpriteType spriteType, ImageFormat imageFormat)
{
	switch (spriteType)
	{
		case SpriteType::Sprite:
		{
			if (imageFormat == ImageFormat::PNG)
			{
				sf::Texture m_Texture;
				
				if (!m_Texture.loadFromFile("Resources/Sprites/Textures" + textureName + ".png"))
				{
					std::cout << "Couldn't locate: Resources/Sprites/Textures" << textureName << ".png" << std::endl;
				}

				m_LoadedSprites.push_back(&m_Texture);
			}
			else if (imageFormat == ImageFormat::JPG)
			{
				sf::Texture m_Texture;

				if (!m_Texture.loadFromFile("Resources/Sprites/Textures" + textureName + ".jpg"))
				{
					std::cout << "Couldn't locate: Resources/Sprites/Textures" << textureName << ".jpg" << std::endl;
				}

				m_LoadedSprites.push_back(&m_Texture);
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