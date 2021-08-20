#pragma once
#include "imgui.h"
#include "../../Style/Style.h"

namespace AutumnEngine
{
	class EditEditorColoursMenu
	{
		public:
			EditEditorColoursMenu();
			~EditEditorColoursMenu();

		public:
			void ShowEditColoursMenu(AutumnEngine::Style& style);
	};
}