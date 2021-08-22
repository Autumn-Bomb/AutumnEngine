#pragma once

#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include "../../../Framework_New/SceneSerializer/SceneSerializer.h"

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
			AutumnEngine::SceneSerializer m_SceneSerializer;

			float m_PanelWidth = 0;
			float m_Padding = 13.f;
			float m_ThumbnailSize = 60.f;
			float m_CellSize = 0;
			int m_ColumnCount = 0;

			char m_Search[128];
			std::filesystem::path m_DefaultPath;
			std::filesystem::path m_CurrentPath;
			std::filesystem::path m_AssetsString = "Assets";

			sf::Sprite m_FolderIcon;
			std::unique_ptr<sf::Texture> m_FolderTexture;

			sf::Sprite m_FileIcon;
			std::unique_ptr<sf::Texture> m_FileTexture;

			sf::Sprite m_FileTextIcon;
			std::unique_ptr<sf::Texture> m_FileTextTexture;
	};
}