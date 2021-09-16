#pragma once
#include <map>
#include <string>

#include "SFML/Graphics/Texture.hpp"

namespace AutumnEngine
{
	class AssetManager
	{
		public:
			AssetManager();
			~AssetManager();

		public:
			void LoadTexture(const char* textureName);

		private:
			std::map<char*, sf::Texture> m_LoadedTextures;

		private:
			sf::Texture* m_Texture;

		private:
			const std::string m_TexturePath;
	};
}