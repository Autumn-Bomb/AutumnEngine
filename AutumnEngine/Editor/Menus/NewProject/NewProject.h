#pragma once

#include "../../Panels/Console/Console.h"
#include "../../Json/json.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

#include<filesystem>
#include <fstream>
#include <iostream>

namespace AutumnEngine
{
	class CreateNewProject
	{
		public:
			CreateNewProject();
			~CreateNewProject();

		public:
			void OpenNewProjectMenu(bool& open, AutumnEngine::Console& console, std::filesystem::path* newProjectPath);
			void CreateProjectDirectory(AutumnEngine::Console& console);

		public:
			char* GetProjectPath() { return m_NewProjectPath; }

		private:
			nlohmann::json m_SceneFile;
			char m_NewProjectName[255];
			char m_NewProjectPath[255];
	};
}