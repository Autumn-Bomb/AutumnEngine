#pragma once
#include "../BasePanel/BasePanel.h"
#include <iostream>
#include <unordered_map>

namespace AutumnEngine
{
	class PanelManager
	{
		public:
			PanelManager();
			~PanelManager();

		public:
			void AddPanel(std::string name, AutumnEngine::Panel* panel);
			void ShowPanels();

		public:
			Panel& GetPanel(std::string name)
			{ 
				auto pairFound = m_Panels.find(name);

				if (pairFound != m_Panels.end())
				{
					return pairFound->second;
				}
			}

		private:
			std::unordered_map<std::string, AutumnEngine::Panel> m_Panels;
	};
}