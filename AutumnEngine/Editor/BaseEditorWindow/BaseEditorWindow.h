#pragma once

#include "../../DearIMGUI/Include/imgui-sfml/imgui-SFML.h"
#include <../../DearIMGUI/Include/imgui/imgui.h>

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

		// SETUP ELEMENTS INSIDE EDITOR
		public:
			void HandleMenuBar();
			void InitialiseHeirarchy();
			void InitialiseInspector();

		public:
			void SetRenderWindow(sf::RenderWindow& window) { m_Window = &window; }

		private:
			sf::RenderWindow* m_Window;
	};
}