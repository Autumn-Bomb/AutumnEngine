#include "SFML/Graphics.hpp"
#include "../Panels/Console/Console.h"

#include "imgui.h"
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

		void ShowHeirarchy();
		void ShowInspector();
		void ShowStats();
		void ShowAnimation();
		void ShowProperties();
		void ShowContentBrowser();
		void ShowSceneViewport();
		void ShowAboutWindow();

		
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

		// Console Methods
		public :

		// GETTERS AND SETTERS
		public:
			void SetRenderWindow(sf::RenderWindow& window) { m_Window = &window; }

		// ENGINE VARIABLES 
		private:
		sf::RenderWindow* m_Window;
		AutumnEngine::Console m_Console;
		std::filesystem::path m_CurrentPath;

		int m_FPS;
		float m_FrameTime;

		char str0[128];
		char m_Search[128];
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