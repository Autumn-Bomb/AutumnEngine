#include "SFML/Graphics.hpp"
#include "imgui-SFML.h"

#include "../Panels/Console/Console.h"
#include "../Panels/Hierarchy/Hierarchy.h"
#include "../Panels/SceneViewport/SceneViewport.h"
#include "../Panels/Inspector/Inspector.h"
#include "../Panels/Stats/Stats.h"
#include "../Panels/Animation/Animation.h"
#include "../Panels/ContentBrowser/ContentBrowser.h"
#include "../Panels/Properties/Properties.h"
#include "../Panels/GameViewport/GameViewport.h"

#include "../Style/Style.h"

#include "../Menus/About/About.h"
#include "../Menus/NewProject/NewProject.h"

#include "../../Framework_New/2DRenderer/2DRenderer.h"

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
			void ProcessEditorEvents(sf::Event& events);
			void UpdateEditorWindow(sf::Clock deltaTime);
			void RenderEditor();
			void ShutDownEditor();

		private:
			void HandleMenuBar();
			void HandleDockSpace();
			void UpdatePanels();

			void AddRectangle();

		public:
			void OpenProjectInExplorer();

		// GETTERS AND SETTERS
		public:
			void SetRenderWindow(sf::RenderWindow& window) { m_Window = &window; }
		
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
			AutumnEngine::Properties m_Properties;

		// MENUS USED IN THE EDITOR
		private:
			AutumnEngine::About m_AboutMenu;
			AutumnEngine::CreateNewProject m_NewProjectMenu;

			AutumnEngine::ImGuiStlye m_Style;

		// ENGINE VARIABLES 
		private:
			sf::RectangleShape rect;
			AutumnEngine::Renderer* m_Renderer;

			sf::RenderWindow* m_Window;
			ImGuiID m_DockSpaceID = 0;
			std::filesystem::path m_CurrentPath;

			int m_FPS;
			float m_FrameTime;

			bool m_ShowInExplorer;
			bool m_ShowAnimation;
			bool m_ShowProperties;
			bool m_ShowContentExplorer;
			bool m_ShowInspectorPanel;
			bool m_ShowStatsPanel;
			bool m_ShowHierarchyPanel;
			bool m_ShowNewProjectPopup;
			bool m_ShowAboutWindow;
			bool m_ShowConsole;
			bool m_ShowSceneViewport;
			bool m_ShowGameViewport;
	};
};