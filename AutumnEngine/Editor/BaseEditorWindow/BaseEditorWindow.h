#include "SFML/Graphics.hpp"

#include "../Panels/Console/Console.h"
#include "../Panels/Hierarchy/Hierarchy.h"
#include "../Panels/SceneViewport/SceneViewport.h"
#include "../Panels/Inspector/Inspector.h"
#include "../Panels/Stats/Stats.h"
#include "../Panels/Animation/Animation.h"
#include "../Panels/ContentBrowser/ContentBrowser.h"
#include "../Panels/Properties/Properties.h"

#include "../Menus/About/About.h"

#include "imgui-SFML.h"

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
			void UpdatePanels();

		public:
			void OpenProjectInExplorer();
			void MakeNewProject();

		// GETTERS AND SETTERS
		public:
			void SetRenderWindow(sf::RenderWindow& window) { m_Window = &window; }

		// ENGINE VARIABLES 
		private:
			sf::RenderWindow* m_Window;
		
		// PANELS USED IN THE EDITOR
		private:
			AutumnEngine::Console m_Console;
			AutumnEngine::Hierarchy m_Hierarchy;
			AutumnEngine::SceneViewport m_SceneViewport;
			AutumnEngine::Inspector m_Inspector;
			AutumnEngine::Stats m_Stats;
			AutumnEngine::Animation m_Animation;
			AutumnEngine::ContentBrowser m_ContentBrowser;
			AutumnEngine::Properties m_Properties;

		// MENUS USED IN THE EDITOR
		private:
			AutumnEngine::About m_AboutMenu;

			std::filesystem::path m_CurrentPath;

			int m_FPS;
			float m_FrameTime;
				
			char str0[128];
			char m_NewProjectName[128];
			char m_NewProjectPath[255];

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
	};
};