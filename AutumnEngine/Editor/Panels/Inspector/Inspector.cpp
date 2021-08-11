#include "../Inspector/Inspector.h"

AutumnEngine::Inspector::Inspector() {}
AutumnEngine::Inspector::~Inspector() {}

void AutumnEngine::Inspector::ShowInspector()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Inspector");

    ImGui::Button("Add Component", ImVec2(ImGui::GetWindowSize().x - 10.f, 30.f));

    ImGui::PopStyleColor();
    ImGui::End();
}