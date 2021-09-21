#include "PanelManager.h"

AutumnEngine::PanelManager::PanelManager() {}
AutumnEngine::PanelManager::~PanelManager() {}

void AutumnEngine::PanelManager::AddPanel(std::string name, AutumnEngine::Panel* panel)
{
	m_Panels[name] = *panel;
}

void AutumnEngine::PanelManager::ShowPanels()
{
	for (std::pair<std::string, AutumnEngine::Panel> panel : m_Panels)
	{
		if (panel.second.GetActiveState())
		{
			panel.second.OnImGuiRender();
		}
	}
}