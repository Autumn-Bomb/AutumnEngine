#include "../Hierarchy/Hierarchy.h"

AutumnEngine::Hierarchy::Hierarchy() { }
AutumnEngine::Hierarchy::~Hierarchy() {}

void AutumnEngine::Hierarchy::ShowHierarchy()
{
    ImGui::Begin("Scene Hierarchy");

    ImGui::Button("Create", ImVec2(50, 20));
    ImGui::SameLine(ImGui::GetWindowWidth() - 100);
    ImGui::PushItemWidth(100);
    ImGui::InputText("##Search", m_Search, IM_ARRAYSIZE(m_Search));
    ImGui::PopItemWidth();
    ImGui::SameLine(ImGui::GetWindowWidth() - 150);
    ImGui::Text("Search");
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