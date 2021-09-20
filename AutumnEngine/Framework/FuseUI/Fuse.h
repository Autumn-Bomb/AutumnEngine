#pragma once
#include "imgui.h"
#include <vector>

namespace AutumnEngine
{
	class Fuse
	{
		public:
			Fuse();
			~Fuse();

		public:
			void CreateWindow(const char* ID, bool* open, ImGuiWindowFlags flags);
			void EndWindow();

		public:
			void AddButton(const char* label, ImVec2 size, bool sameLine = false);
			void AddText(const char* text, bool sameLine = false);
			void AddSeperator();

		private:
	};
}