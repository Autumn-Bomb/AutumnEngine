#include "../Inspector/Inspector.h"

AutumnEngine::Inspector::Inspector() {}
AutumnEngine::Inspector::~Inspector() {}

void AutumnEngine::Inspector::ShowInspector()
{
    ImGui::Begin("Inspector");

    ImGui::Button("Add Component", ImVec2(ImGui::GetWindowSize().x - 10.f, 30.f));

    ImGui::End();
}