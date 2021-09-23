#include "Animation.h"

AutumnEngine::Animation::Animation() {}
AutumnEngine::Animation::~Animation() {}

void AutumnEngine::Animation::OnImGuiRender()
{
    ImGui::Begin("Animation");

    ImGui::Button("Load Animation", ImVec2(110, 25));
    ImGui::Separator();
    ImGui::Text("Animated Entity:");
    ImGui::Text("Animation Name:");
    ImGui::Text("Animation Frames:");

    ImGui::End();
}