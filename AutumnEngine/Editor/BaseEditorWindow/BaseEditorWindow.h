#pragma once

#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "../imgui-sfml/imgui-SFML.h"

#include "SFML/Graphics.hpp"
#include <filesystem>

namespace AutumnEngine
{
	class BaseEditorWindow
	{
		// CONSTRUCTORS
		public:
			BaseEditorWindow();
			~BaseEditorWindow();

		// INITIALISE EDITOR WINDOW
		public:
			void InitialiseEditor();
			void ProcessEditorEvents(sf::Event& events);
			void UpdateEditorWindow(sf::Clock deltaTime);
			void RenderEditor();

			void ShutDownEditor();

		// UPDATE PANELS (DISPLAYING OR NOT DISPLAYING)
		public:
			void UpdatePanels();

		// SETUP ELEMENTS INSIDE EDITOR
		public:
			void HandleMenuBar();
			void ShowHeirarchy();
			void ShowInspector();
			void ShowStats();
			void ShowConsole();
			void ShowAnimation();
			void ShowProperties();
			void ShowContentBrowser();
			void ShowSceneViewport();

			void ShowAboutWindow();

			void OpenProjectInExplorer();

		// GETTERS AND SETTERS
		public:
			void SetRenderWindow(sf::RenderWindow& window) { m_Window = &window; }

		// PRIVATE VARIABLES WE DON'T NEED OTHER CLASSES TO ACCESS
		private:
			sf::RenderWindow* m_Window;

		// ENGINE VARIABLES 
		private:
			int m_FPS;
			float m_FrameTime;

			char str0[128];

			bool m_ShowAnimation;
			bool m_ShowProperties;
			bool m_ShowContentExplorer;
			bool m_ShowSceneViewport;
			bool m_ShowConsole;
			bool m_ShowAboutWindow;
			bool m_ShowInspectorPanel;
			bool m_ShowStatsPanel;
			bool m_ShowHierarchyPanel;
	};
}