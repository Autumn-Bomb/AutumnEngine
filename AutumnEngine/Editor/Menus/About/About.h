#pragma once

#include "imgui.h"

namespace AutumnEngine
{
	class About
	{
		public:
			About();
			~About();

		public:
			void ShowAboutMenu(bool& open);
	};
}