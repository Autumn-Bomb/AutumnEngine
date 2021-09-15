#include "../Inspector/Inspector.h"

AutumnEngine::Inspector::Inspector() { m_Entity = nullptr; }
AutumnEngine::Inspector::~Inspector() {}

void AutumnEngine::Inspector::ShowInspector()
{
    ImGui::Begin("Inspector");

    if (m_Entity != nullptr)
        ImGui::Button("Add Component", ImVec2(ImGui::GetWindowSize().x - 10.f, 30.f));

    ImGui::End();
}