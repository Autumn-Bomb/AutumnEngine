#include "Animation.h"

AutumnEngine::Animation::Animation() {}
AutumnEngine::Animation::~Animation() {}

void AutumnEngine::Animation::ShowAnimation()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Animation");

    ImGui::Text("Animation Name:");

    ImGui::PopStyleColor();
    ImGui::End();
}