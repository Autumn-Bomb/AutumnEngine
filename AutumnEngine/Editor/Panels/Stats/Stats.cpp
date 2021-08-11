#include "Stats.h"

AutumnEngine::Stats::Stats() {}
AutumnEngine::Stats::~Stats() {}

void AutumnEngine::Stats::ShowStats(int& fps, float& frameTime)
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Stats");

    ImGui::Text("FPS: %i", fps);
    ImGui::Text("Frame Time: %f", frameTime);

    ImGui::Text("Entities: %f", 0);
    ImGui::Text("Batches: %f", 0);
    ImGui::Text("Vertices: %f", 0);

    ImGui::PopStyleColor();
    ImGui::End();
}