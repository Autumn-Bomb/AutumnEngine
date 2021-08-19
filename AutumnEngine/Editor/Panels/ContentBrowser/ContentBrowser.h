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
			~ContentBrowser();

		public:
			void ShowContentBrowser();
			void ShowLoadedProjectContent();

			void CreateNewFolder();
			void CreateNewFile();

			void RefreshDirectory();

			void UpdateProjectPath(std::filesystem::path& projectDirectory);

		private:
			char m_Search[48];
			std::filesystem::path m_DefaultPath;
			std::filesystem::path m_CurrentPath;
			std::filesystem::path m_AssetsString = "Assets";

			sf::Sprite m_FolderIcon;
			std::unique_ptr<sf::Texture> m_FolderTexture;
	};
}