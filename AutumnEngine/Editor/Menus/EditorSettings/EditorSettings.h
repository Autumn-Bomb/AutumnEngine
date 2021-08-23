#pragma once
#include "imgui.h"

namespace AutumnEngine
{
	class EditorSettings
	{
		public:
			EditorSettings();
			~EditorSettings();

		public:
			void OnImGuiRender(bool& open);
	};
}