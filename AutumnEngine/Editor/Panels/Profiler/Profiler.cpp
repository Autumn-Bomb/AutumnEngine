#include "Profiler.h"
#include <string>

AutumnEngine::Profiler::Profiler() { m_FPS = 0; m_FrameTime = 0; }
AutumnEngine::Profiler::~Profiler() {}

void AutumnEngine::Profiler::OnImGuiRender()
{
    CalculateFPSAndFrameTime();

    ImGui::Begin("Profiler", &GetActiveState());

    ImGui::Text("FPS: %i", m_FPS);
    ImGui::Text("Frame Time: %f", m_FrameTime);
   
    ImGui::Separator();

    ImGui::Text("Draw Calls: %i", 0);
    ImGui::Text("Sprites: %i", 0);
    ImGui::Text("Entities: %i", 0);
    ImGui::Text("Batches: %i", 0);
    ImGui::Text("Vertices: %i", 0);
    ImGui::Text("Memory: %i", 0);

    ImGui::End();
}

void AutumnEngine::Profiler::CalculateFPSAndFrameTime()
{
    m_FPS = 1 / ImGui::GetIO().DeltaTime;
    m_FrameTime = 0.1f / m_FPS;
}