#include "SFML/Graphics.hpp"
#include "imgui-SFML.h"

#include "../Panels/Console/Console.h"
#include "../Panels/Hierarchy/Hierarchy.h"
#include "../Panels/SceneViewport/SceneViewport.h"
#include "../Panels/Inspector/Inspector.h"
#include "../Panels/Stats/Stats.h"
#include "../Panels/Animation/Animation.h"
#include "../Panels/ContentBrowser/ContentBrowser.h"
#include "../Panels/GameViewport/GameViewport.h"

#include "../Style/Style.h"

#include "../Menus/EditorSettings/EditorSettings.h"
#include "../Menus/About/About.h"
#include "../Menus/NewProject/NewProject.h"
#include "../Menus/OpenProject/OpenProject.h"

#include "../../Framework/2DRenderer/2DRenderer.h"
#include "../../Framework/SceneSerializer/SceneSerializer.h"

#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <shellapi.h>

namespace AutumnEngine
{
	class BaseEditorWindow
	{
		public:
			BaseEditorWindow();
			~BaseEditorWindow();

		// Editor Methods
		public:
			void InitialiseEditor();
			void LoadEditorIcons();
			void ProcessEditorEvents(sf::Event& events);
			void UpdateEditorWindow(sf::Clock deltaTime);
			void RenderEditor();
			void ShutDownEditor();

		private:
			void HandleMenuBar();
			void HandleDockSpace();
			void HandleControlButtons();
			void UpdatePanels();

		// GETTERS AND SETTERS
		public:
			void SetRenderWindow(sf::RenderWindow& window) { m_Window = &window; }

		// MENUS USED IN THE EDITOR
		private:
			AutumnEngine::Style m_Style;

		// ENGINE VARIABLES 
		private:
			AutumnEngine::Renderer m_Renderer;

			sf::Sprite m_PlayButtonIcon;
			std::unique_ptr<sf::Texture> m_PlayButtonTexture;

			sf::Sprite m_PauseButtonIcon;
			std::unique_ptr<sf::Texture> m_PauseButtonTexture;

			sf::Sprite m_StopButtonIcon;
			std::unique_ptr<sf::Texture> m_StopButtonTexture;

			sf::RenderWindow* m_Window;
			ImGuiID m_DockSpaceID = 0;

			std::filesystem::path m_CurrentPath;

			int m_FPS;
			float m_FrameTime;

			bool m_ShowAnimation;
			bool m_ShowContentExplorer;
			bool m_ShowInspectorPanel;
			bool m_ShowStatsPanel;
			bool m_ShowHierarchyPanel;
			bool m_ShowNewProjectPopup;
			bool m_ShowOpenProjectPopup;
			bool m_ShowAboutWindow;
			bool m_ShowConsole;
			bool m_ShowSceneViewport;
			bool m_ShowGameViewport;
			bool m_ShowEditorSettings;

		// MENUS USED IN THE EDITOR
		private:
			AutumnEngine::About m_AboutMenu;
			AutumnEngine::CreateNewProject m_NewProjectMenu;
			AutumnEngine::OpenProjectMenu m_OpenProjectMenu;
			AutumnEngine::EditorSettings m_EditorSettings;

		// PANELS USED IN THE EDITOR
		private:
			AutumnEngine::Console m_Console;
			AutumnEngine::Hierarchy m_Hierarchy;
			AutumnEngine::SceneViewport m_SceneViewport;
			AutumnEngine::GameViewport m_GameViewport;
			AutumnEngine::Inspector m_Inspector;
			AutumnEngine::Stats m_Stats;
			AutumnEngine::Animation m_Animation;
			AutumnEngine::ContentBrowser m_ContentBrowser;
	};
};