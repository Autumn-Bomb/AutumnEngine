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
		public:
			enum class SpriteType { UI, Sprite, Logo };
			enum class ImageFormat { PNG, JPG };

			enum class SoundType { WAV, MP3 };

			AssetManager();
			~AssetManager();

			void CheckIfDirectoriesExist(std::string folderPath);

			void LoadTexture(std::string textureName, std::string resourceName, SpriteType spriteType, ImageFormat imageFormat);
			void LoadSound(std::string soundName, SoundType soundType);
			void LoadTileMapJson(std::string fileName);

			sf::Texture& GetTexture(std::string fileName);

		private:
			std::map<std::string, sf::Texture*> m_LoadedTextures;
			sf::Texture* m_NewTexture;
		    nlohmann::json m_TileMapFile;
	};
}