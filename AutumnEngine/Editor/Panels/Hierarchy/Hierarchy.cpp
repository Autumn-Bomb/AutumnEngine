#include "../Hierarchy/Hierarchy.h"

AutumnEngine::Hierarchy::Hierarchy() { }
AutumnEngine::Hierarchy::~Hierarchy() {}

void AutumnEngine::Hierarchy::OnImGuiRender()
{
    ImGui::Begin("Scene Hierarchy");

    if (ImGui::Button("Create", ImVec2(50, 20))) { OnCreateButton(); }
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

void AutumnEngine::Hierarchy::OnCreateButton()
{
    ImGui::BeginPopupContextWindow("Tools", ImGuiPopupFlags_None);
    
    if (ImGui::MenuItem("Empty Entity")) { }
    ImGui::Separator();
    if (ImGui::MenuItem("Sprite")) { }
    ImGui::Separator();

    ImGui::EndPopup();
}