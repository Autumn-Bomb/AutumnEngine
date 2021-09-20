#pragma once
#include "../imgui/imgui.h"
#include <iostream>
#include <unordered_map>
namespace AutumnEngine
{
	class Hierarchy
	{
		public:
			Hierarchy();
			~Hierarchy();

		public:
			void ShowHierarchy();

			void DisplayNodes();
			void AddEntityToSceneGraph(std::string name);
			void OnCreateButton();

		private:
			char m_Search[128];
	};
}