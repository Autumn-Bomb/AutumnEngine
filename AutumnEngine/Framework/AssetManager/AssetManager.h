#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Json/json.hpp"

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
			void LoadTextureAtlas(std::string filePath, std::string resourceName);
			void LoadJSON(std::string filePath, std::string jsonFileName);
			void LoadFont(std::string filePath, std::string resourceName);
			void ClearAssets() { DeleteAssets(m_LoadedTextures); DeleteAssets(m_LoadedTextureAtlases); };

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
		
		// GETTERS AND SETTERS
		public:
			sf::Texture& GetTexture(std::string fileName);
			sf::Texture& GetTextureAtlas(std::string fileName);
			sf::Font& GetFont(std::string fontName);
			nlohmann::json& GetJSON(std::string jsonName);

		// RESOURCE MAPS 
		private:
			std::map<std::string, sf::Texture*> m_LoadedTextures;
			std::map<std::string, sf::Texture*> m_LoadedTextureAtlases;
			std::map<std::string, sf::Font*> m_LoadedFonts;
			std::map<std::string, nlohmann::json*> m_LoadedJSON;

		// CONTAINERS FOR LOADED RESOURCES
		private:
			sf::Texture* m_NewTexture;
			sf::Texture* m_NewTextureAtlas;
			sf::Font* m_NewFont;
			nlohmann::json* m_JsonFile;
	};
}