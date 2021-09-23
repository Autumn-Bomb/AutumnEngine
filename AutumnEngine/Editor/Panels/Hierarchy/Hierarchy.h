#pragma once
#include <unordered_map>
#include "../BasePanel/BasePanel.h"

namespace AutumnEngine
{
	class Hierarchy : public AutumnEngine::Panel
	{
		public:
			Hierarchy();
			~Hierarchy();

		public:
			void OnImGuiRender() override;

			void DisplayNodes();
			void AddEntityToSceneGraph(std::string name);
			void OnCreateButton();

		private:
			char m_Search[128];
	};
}