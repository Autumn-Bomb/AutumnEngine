#pragma once

#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include "../imgui-sfml/imgui-SFML.h"

#include "SFML/Graphics.hpp"

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
			void InitialiseHeirarchy();
			void InitialiseInspector();
			void InitialiseStats();

		// GETTERS AND SETTERS
		public:
			void SetRenderWindow(sf::RenderWindow& window) { m_Window = &window; }

		// PRIVATE VARIABLES WE DON'T NEED OTHER CLASSES TO ACCESS
		private:
			float m_FPS;
			float m_FrameTime;

			sf::RenderWindow* m_Window;
			bool m_ShowInspectorPanel;
			bool m_ShowStatsPanel;
			bool m_ShowHierarchyPanel;
	};
}