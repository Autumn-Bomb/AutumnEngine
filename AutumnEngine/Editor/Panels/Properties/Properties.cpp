#include "Properties.h"

AutumnEngine::Properties::Properties() {}
AutumnEngine::Properties::~Properties() {}

void AutumnEngine::Properties::ShowProperties()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Properties");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();
}