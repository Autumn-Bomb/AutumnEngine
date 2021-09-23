#include "SFML/Graphics.hpp"
#include "../../../Editor/Panels/PanelManager/PanelManager.h"

#include "../Panels/Console/Console.h"
#include "../Panels/Hierarchy/Hierarchy.h"
#include "../Panels/SceneViewport/SceneViewport.h"
#include "../Panels/Inspector/Inspector.h"
#include "../Panels/Profiler/Profiler.h"
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

#include <time.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <shellapi.h>
#include <math.h>

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
			void UpdateEditorWindow(sf::Clock& deltaTime);
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
			AutumnEngine::PanelManager m_PanelManager;
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

			bool m_ShowNewProjectPopup;
			bool m_ShowOpenProjectPopup;

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
			AutumnEngine::Profiler m_Profiler;
			AutumnEngine::Animation m_Animation;
			AutumnEngine::ContentBrowser m_ContentBrowser;
	};
};