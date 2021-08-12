#include "Stats.h"

AutumnEngine::Stats::Stats() {}
AutumnEngine::Stats::~Stats() {}

void AutumnEngine::Stats::ShowStats(int& fps, float& frameTime)
{
    ImGui::Begin("Stats");

    ImGui::Text("FPS: %i", fps);
    ImGui::Text("Frame Time: %f", frameTime);
   
    ImGui::Separator();

    ImGui::Text("Draw Calls: %i", 0);
    ImGui::Text("Entities: %i", 0);
    ImGui::Text("Batches: %i", 0);
    ImGui::Text("Vertices: %i", 0);

    ImGui::End();
}