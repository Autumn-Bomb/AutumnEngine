#include "../SceneViewport/SceneViewport.h"

AutumnEngine::SceneViewport::SceneViewport(){}
AutumnEngine::SceneViewport::~SceneViewport() {}

void AutumnEngine::SceneViewport::ShowSceneViewport()
{
    ImGui::Begin("Scene Viewport", NULL, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_None);

    if (!m_RendererCreated)
    {
        m_Renderer->Create(ImGui::GetWindowWidth() - 25.f, ImGui::GetWindowHeight() - 65.f);
        m_RendererCreated = true;
    }

    ImGui::SameLine(ImGui::GetWindowWidth() / 2 - 60);
    ImGui::Button("Play", ImVec2(40, 20));
    ImGui::SameLine();
    ImGui::Button("Pause", ImVec2(40, 20));
    ImGui::SameLine();
    ImGui::Button("Stop", ImVec2(40, 20));

    ImGui::Separator();

    ImGui::Image(*m_Renderer->GetRenderTexture(), sf::Color::White);

    ImGui::End();
}