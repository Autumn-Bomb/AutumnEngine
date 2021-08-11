#include "ContentBrowser.h"

AutumnEngine::ContentBrowser::ContentBrowser() {}
AutumnEngine::ContentBrowser::~ContentBrowser() {}

void AutumnEngine::ContentBrowser::ShowContentBrowser()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Content Browser");

    // INSERT CONTENT HERE
    ImGui::Button("Back", ImVec2(45, 20));
    ImGui::SameLine();
    ImGui::Text("Path: ");

    ImGui::Separator();

    ImGui::PopStyleColor();
    ImGui::End();
}