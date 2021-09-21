#include "Profiler.h"
#include <string>

AutumnEngine::Profiler::Profiler() {}
AutumnEngine::Profiler::~Profiler() {}

void AutumnEngine::Profiler::ShowStats(unsigned int& fps, float& frameTime)
{
    ImGui::Begin("Profiler");

    ImGui::Text("FPS: %i", fps);
    ImGui::Text("Frame Time: %f", frameTime);
   
    ImGui::Separator();

    ImGui::Text("Draw Calls: %i", 0);
    ImGui::Text("Sprites: %i", 0);
    ImGui::Text("Entities: %i", 0);
    ImGui::Text("Batches: %i", 0);
    ImGui::Text("Vertices: %i", 0);
    ImGui::Text("Memory: %i", 0);

    ImGui::End();
}