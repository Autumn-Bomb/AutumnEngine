#pragma once
#include "../../Panels/Console/Console.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <direct.h>

namespace AutumnEngine
{
	class OpenProjectMenu
	{
		public:
			OpenProjectMenu();
			~OpenProjectMenu();

		public:
			void OpenProject(bool& open, AutumnEngine::Console& console, std::filesystem::path* newProjectPath);

		public:
			char* GetProjectPath() { return m_ExistingProjectPath; }

		private:
			char m_ExistingProjectPath[255];
	};
}