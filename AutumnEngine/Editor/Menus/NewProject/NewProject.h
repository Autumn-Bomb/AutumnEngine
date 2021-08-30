#pragma once

#include "../../Panels/Console/Console.h"
#include<filesystem>
#include <fstream>
#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"

namespace AutumnEngine
{
	class CreateNewProject
	{
		public:
			CreateNewProject();
			~CreateNewProject();

		public:
			void OpenNewProjectMenu(bool& open, AutumnEngine::Console& console, std::filesystem::path* newProjectPath);
			void ChooseProjectPath();
			void CreateProjectDirectory(AutumnEngine::Console& console);

		public:
			char* GetProjectPath() { return m_NewProjectPath; }

		private:
			char m_NewProjectName[255];
			char m_NewProjectPath[255];
	};
}