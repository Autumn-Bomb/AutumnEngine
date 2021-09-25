#pragma once

#include "SFML/Graphics.hpp"
#include "../BasePanel/BasePanel.h"

#include <fstream>
#include <iostream>
#include <filesystem>

namespace AutumnEngine
{
	class ContentBrowser : public AutumnEngine::Panel
	{
		public:			
			ContentBrowser();
			~ContentBrowser();

		public:
			void OnImGuiRender() override;
			void ShowLoadedProjectContent();
			void ShowProjectTree();

			void CreateNewFolder();
			void CreateNewFile();

			void RefreshProject();

			void UpdateProjectPath(std::filesystem::path& projectDirectory);

		public:
			void SetThumbnailPadding(float padding) { m_ThumbnailPadding = padding; }
			void SetThumbnailSize(float size) { m_ThumbnailSize = size; }

			bool* GetIsCompact() { return &m_IsCompact; }
			float* GetThumbnailPadding() { return &m_ThumbnailPadding; }
			float* GetThumbnailSize() { return &m_ThumbnailSize; }

		private:
			bool m_IsCompact;
			bool m_SameLineText;

			float m_PanelWidth = 0;
			float m_ThumbnailPadding = 13.f;
			float m_ThumbnailSize = 60.f;
			float m_CellSize = 0;
			int m_ColumnCount = 0;

			char m_Search[128];
			char m_NewFolderName[128] = "Folder";
			char m_NewFileName[128] = "Test.txt";

			std::filesystem::path m_DefaultPath;
			std::filesystem::path m_CurrentPath;
			std::filesystem::path m_AssetsString = "Assets";

			// TOGO WHEN THE ASSET MANAGER IS IMPLEMENTED
			sf::Sprite m_FolderIcon;
			std::unique_ptr<sf::Texture> m_FolderTexture;

			sf::Sprite m_FileCodeIcon;
			std::unique_ptr<sf::Texture> m_FileCodeTexture;

			sf::Sprite m_FileSceneIcon;
			std::unique_ptr<sf::Texture> m_FileSceneTexture;

			sf::Sprite m_FileIcon;
			std::unique_ptr<sf::Texture> m_FileTexture;

			sf::Sprite m_FileTextIcon;
			std::unique_ptr<sf::Texture> m_FileTextTexture;
	};
}