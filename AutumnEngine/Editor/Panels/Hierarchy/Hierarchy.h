#pragma once
#include "../imgui/imgui.h"

namespace AutumnEngine
{
	class Hierarchy
	{
		public:
			Hierarchy();
			~Hierarchy();

		public:
			void ShowHierarchy();

		private:
			char m_Search[128];
	};
}