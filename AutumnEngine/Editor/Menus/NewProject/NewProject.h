#pragma once

#include "../../Panels/Console/Console.h"
#include <iostream>

namespace AutumnEngine
{
	class CreateNewProject
	{
		public:
			CreateNewProject();
			~CreateNewProject();

		public:
			void OpenNewProjectMenu(bool& open, AutumnEngine::Console& console);
			void CreateProjectDirectory(AutumnEngine::Console& console);

		private:
			char m_NewProjectName[128] = "";
			char m_NewProjectPath[511] = "";
	};
}