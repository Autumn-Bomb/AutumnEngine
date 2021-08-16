#include "../Hierarchy/Hierarchy.h"

AutumnEngine::Hierarchy::Hierarchy() { }
AutumnEngine::Hierarchy::~Hierarchy() {}

void AutumnEngine::Hierarchy::ShowHierarchy()
{
    ImGui::Begin("Scene Hierarchy");

    ImGui::Button("Create", ImVec2(50, 18));
    ImGui::SameLine();
    ImGui::InputText("##Search", m_Search, IM_ARRAYSIZE(m_Search));
    ImGui::Separator();

    DisplayNodes();

    ImGui::End();
}

void AutumnEngine::Hierarchy::AddEntityToSceneGraph(std::string name)
{
    
}

void AutumnEngine::Hierarchy::DisplayNodes()
{

}