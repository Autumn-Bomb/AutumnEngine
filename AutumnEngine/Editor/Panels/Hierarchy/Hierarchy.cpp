#include "../Hierarchy/Hierarchy.h"

AutumnEngine::Hierarchy::Hierarchy() { }
AutumnEngine::Hierarchy::~Hierarchy() {}

void AutumnEngine::Hierarchy::ShowHierarchy()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Scene Hierarchy");

    ImGui::Button("Create", ImVec2(50, 18));
    ImGui::SameLine();
    ImGui::InputText("", m_Search, IM_ARRAYSIZE(m_Search));
    ImGui::Separator();

    ImGui::PopStyleColor();
    ImGui::End();
}