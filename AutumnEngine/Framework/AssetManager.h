#pragma once
#include "SFML/Graphics.hpp"
#include "json.hpp"

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
		
		// RESOURCE DEFINITIONS
		public:
			enum class SpriteType { UI, Sprite, Texture, Logo, TextureAtlas, SpriteSheet };
			enum class ImageFormat { PNG, JPG };
			enum class SoundType { WAV, MP3, OGG };
			
		// METHOD DEFINITIONS
		public:
			void CheckIfDirectoriesExist(std::string folderPath);
			void LoadTexture(std::string textureName, std::string resourceName, SpriteType spriteType, ImageFormat imageFormat);
			void LoadSound(std::string soundName, SoundType soundType);
			void LoadJSON(std::string fileName, std::string jsonFileName);
			void LoadFont(std::string fontName, std::string resourceName);
			void ClearAssets() { DeleteAssets(m_LoadedTextures); };

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
			sf::Font& GetFont(std::string fontName);
			nlohmann::json& GetJSON(std::string jsonName);

		// RESOURCE MAPS 
		private:
			std::map<std::string, sf::Texture*> m_LoadedTextures;
			std::map<std::string, sf::Font*> m_LoadedFonts;
			std::map<std::string, nlohmann::json*> m_LoadedJSON;

		// CONTAINERS FOR LOADED RESOURCES
		private:
			sf::Texture* m_NewTexture;
			sf::Font* m_NewFont;
			nlohmann::json* m_JsonFile;

		// STRINGS FOR PATH AND EXTENSION NAMES
		private:
			std::string m_FileExtension;
			std::string m_FilePath;
	};
}