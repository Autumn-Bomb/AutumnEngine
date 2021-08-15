#include "../SceneViewport/SceneViewport.h"

AutumnEngine::SceneViewport::SceneViewport() { m_Renderer = nullptr; m_RendererCreated = false; }
AutumnEngine::SceneViewport::~SceneViewport() {}

void AutumnEngine::SceneViewport::ShowSceneViewport()
{
    ImGui::Begin("Scene Viewport", NULL, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_None);

    ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;

    ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);

    if (!m_RendererCreated)
    {
        m_Renderer->Create(vWindowSize.x, vWindowSize.y);
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