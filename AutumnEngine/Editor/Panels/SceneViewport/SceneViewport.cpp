#include "../SceneViewport/SceneViewport.h"#

AutumnEngine::SceneViewport::SceneViewport() {}
AutumnEngine::SceneViewport::~SceneViewport() {}

void AutumnEngine::SceneViewport::ShowSceneViewport()
{
    ImGui::Begin("Scene Viewport");

    ImGui::SameLine(ImGui::GetWindowWidth() / 2 - 60);
    ImGui::Button("Play", ImVec2(40, 20));
    ImGui::SameLine();
    ImGui::Button("Pause", ImVec2(40, 20));
    ImGui::SameLine();
    ImGui::Button("Stop", ImVec2(40, 20));

    ImGui::Separator();

    ImGui::End();
}