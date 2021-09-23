#include "PanelManager.h"

AutumnEngine::PanelManager::PanelManager() {}
AutumnEngine::PanelManager::~PanelManager() {}

void AutumnEngine::PanelManager::AddPanel(std::string name, AutumnEngine::Panel* panel)
{
	m_Panels[name] = panel;
	std::cout << "\nPanel Added:" << name;
	std::cout << "\nPanel State:" << panel->GetActiveState();
}

void AutumnEngine::PanelManager::ShowPanels()
{
	for (auto& panel : m_Panels)
	{
		if (panel.second->GetActiveState())
			panel.second->OnImGuiRender();
		else
			return;
	}
}