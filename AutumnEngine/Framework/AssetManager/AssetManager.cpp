#include "AssetManager.h"

AutumnEngine::AssetManager::AssetManager() { m_NewTexture = nullptr; m_JsonFile = nullptr; m_NewFont = nullptr; }
AutumnEngine::AssetManager::~AssetManager() {}

void AutumnEngine::AssetManager::LoadTexture(std::string filePath, std::string resourceName)
{
	m_NewTexture = new sf::Texture();

	if (!m_NewTexture->loadFromFile(filePath))
	{
		std::cout << "Couldn't locate: " << filePath << std::endl;
	}
	m_LoadedTextures[resourceName] = m_NewTexture;
}

void AutumnEngine::AssetManager::CreateTextureAtlas(std::string filePath, std::string resourceName)
{
	sf::Texture* textureAtlas = new sf::Texture();
	textureAtlas->loadFromFile(filePath);

	AutumnEngine::TextureAtlas* m_NewTextureAtlas = new AutumnEngine::TextureAtlas(textureAtlas);
	m_LoadedTextureAtlases[resourceName] = m_NewTextureAtlas;

	std::cout << "Texture Atlas Loaded: " << filePath << std::endl;
}

void AutumnEngine::AssetManager::CreateSpriteSheet(std::string filePath, std::string resourceName)
{
	sf::Texture* spritesheet = new sf::Texture();
	spritesheet->loadFromFile(filePath);

	AutumnEngine::Spritesheet* m_NewSpriteSheet = new AutumnEngine::Spritesheet(spritesheet);
	m_LoadedSpritesheet[resourceName] = m_NewSpriteSheet;

	std::cout << "Spritesheet Loaded: " << filePath << std::endl;
}

void AutumnEngine::AssetManager::LoadFont(std::string filePath, std::string resourceName)
{
	if (m_NewFont == nullptr)
	{
		m_NewFont = new sf::Font();

		if (!m_NewFont->loadFromFile(filePath))
		{
			std::cout << "Unable to load in font from: " << filePath;
			return;
		}
		m_LoadedFonts[resourceName] = m_NewFont;
	}
	else
	{
		return;
	}
}

sf::Texture& AutumnEngine::AssetManager::GetTexture(std::string fileName)
{
	auto pairFound = m_LoadedTextures.find(fileName);

	if (pairFound != m_LoadedTextures.end())
	{
		return *pairFound->second;
	}
}

AutumnEngine::TextureAtlas& AutumnEngine::AssetManager::GetTextureAtlas(std::string fileName)
{
	auto pairFound = m_LoadedTextureAtlases.find(fileName);

	if (pairFound != m_LoadedTextureAtlases.end())
	{
		return *pairFound->second;
	}
}

AutumnEngine::Spritesheet& AutumnEngine::AssetManager::GetSpriteSheet(std::string fileName)
{
	auto pairFound = m_LoadedSpritesheet.find(fileName);

	if (pairFound != m_LoadedSpritesheet.end())
	{
		return *pairFound->second;
	}
}

sf::Font& AutumnEngine::AssetManager::GetFont(std::string fontName)
{
	auto pairFound = m_LoadedFonts.find(fontName);

	if (pairFound != m_LoadedFonts.end())
	{
		return *pairFound->second;
	}
	else
	{
		sf::Font* newFont = new sf::Font();

		std::cout << "Resource: " << fontName << ".ttf doesn't exist in Asset Manager, searching for file now" << std::endl;
		newFont->loadFromFile("Resources/Fonts/" + fontName + ".ttf");
		m_LoadedFonts[fontName] = newFont;

		return *newFont;
	}
}

void AutumnEngine::AssetManager::LoadJSON(std::string filePath, std::string jsonFileName)
{
	m_JsonFile = new nlohmann::json;

	std::ifstream stream(filePath); // create a new ifStream called "filePath" and load in the json file specified
	stream >> *m_JsonFile; // copy all contents of the loaded file into the JSON

	m_LoadedJSON[jsonFileName] = m_JsonFile;

	std::cout << "JSON File " << filePath << " loaded successfully" << std::endl;
}

nlohmann::json& AutumnEngine::AssetManager::GetJSON(std::string fileName)
{
	auto pairFound = m_LoadedJSON.find(fileName);

	if (pairFound != m_LoadedJSON.end())
	{
		return *pairFound->second;
	}
	else
	{
		nlohmann::json* newJson = new nlohmann::json;

		std::cout << "Resource: " << fileName << " doesn't exist in Asset Manager, searching for file now" << std::endl;
		std::ifstream filePath("Resources/JSON/" + fileName + ".json"); // create a new ifStream called "filePath" and load in the json file specified
		filePath >> *m_JsonFile; // copy all contents of the loaded file into the JSON
		m_LoadedJSON[fileName] = newJson;

		return *newJson;
	}
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