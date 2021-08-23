#include "EditorSettings.h"

AutumnEngine::EditorSettings::EditorSettings() {}
AutumnEngine::EditorSettings::~EditorSettings() {}

void AutumnEngine::EditorSettings::OnImGuiRender(bool& open)
{
	ImGui::Begin("Editor Settings");
	ImGui::Text("Use this menu to change the available Editor Settings");
	if (ImGui::Button("Apply", ImVec2(50, 50))) { open = !open; }
	ImGui::Separator();
	ImGui::End();
}