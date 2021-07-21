#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Json/json.hpp"
#include "../TextureAtlas/TextureAtlas.h"
#include "../Spritesheets/Spritesheet.h"

#include <filesystem>
#include <iostream>
#include <fstream>

namespace AutumnEngine
{
	class AssetManager
	{
		// CONSTRUCTORS AND DESTRUCTOR
		public:
			AssetManager();
			~AssetManager();

		// METHOD DEFINITIONS
		public:
			void CheckIfDirectoriesExist(std::string folderPath);
			void LoadTexture(std::string filePath, std::string resourceName);
			void LoadJSON(std::string filePath, std::string jsonFileName);
			void LoadFont(std::string filePath, std::string resourceName);
			void ClearAssets() { DeleteAssets(m_LoadedTextures); DeleteAssets(m_LoadedTextureAtlases); DeleteAssets(m_LoadedSpritesheet); }

		// TEMPLATE FUNCTION TO DELETE OBJECTS FROM VECTORS (ALL ASSETS STORED)
		public:
			template <typename M>
			void DeleteAssets(M& amap)
			{
				for (typename M::iterator it = amap.begin(); it != amap.end(); ++it)
				{
					std::cout << "Deleting: " << it->first << std::endl;
					delete it->second;
				}
				amap.clear();
			}

		// CREATION OF ASSET DEFINITIONS
		public:
			void CreateTextureAtlas(std::string filePath, std::string resourceName);
			void CreateSpriteSheet(std::string filePath, std::string resourceName);

		// GETTERS AND SETTERS
		public:
			sf::Texture& GetTexture(std::string fileName);
			AutumnEngine::TextureAtlas& GetTextureAtlas(std::string fileName);
			AutumnEngine::Spritesheet& GetSpriteSheet(std::string fileName);
			sf::Font& GetFont(std::string fontName);
			nlohmann::json& GetJSON(std::string jsonName);

		// RESOURCE MAPS 
		private:
			std::map<std::string, sf::Texture*> m_LoadedTextures;
			std::map<std::string, AutumnEngine::TextureAtlas*> m_LoadedTextureAtlases;
			std::map<std::string, AutumnEngine::Spritesheet*> m_LoadedSpritesheet;
			std::map<std::string, sf::Font*> m_LoadedFonts;
			std::map<std::string, nlohmann::json*> m_LoadedJSON;

		// CONTAINERS FOR LOADED RESOURCES
		private:
			sf::Texture* m_NewTexture;
			sf::Font* m_NewFont;

			nlohmann::json* m_JsonFile;
	};
}