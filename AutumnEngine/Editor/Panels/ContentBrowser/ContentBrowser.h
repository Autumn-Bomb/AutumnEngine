#pragma once

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

#include <iostream>
#include <filesystem>

namespace AutumnEngine
{
	class ContentBrowser
	{
		public:			
			ContentBrowser();
			ContentBrowser(std::filesystem::path& projectDirectory);
			~ContentBrowser();

		public:
			void ShowContentBrowser();
			void ShowLoadedProjectContent();

		private:
			std::filesystem::path m_DefaultPath;
			std::filesystem::path m_CurrentPath;
			std::filesystem::path m_AssetsString = "Assets";

			sf::Sprite m_FolderIcon;
			std::unique_ptr<sf::Texture> m_FolderTexture;
	};
}