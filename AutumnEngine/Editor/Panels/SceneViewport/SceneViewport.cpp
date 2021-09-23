#include "../SceneViewport/SceneViewport.h"

AutumnEngine::SceneViewport::SceneViewport()
{
    m_Renderer = nullptr;
    m_RendererCreated = false; 
}
AutumnEngine::SceneViewport::~SceneViewport() {}

void AutumnEngine::SceneViewport::OnImGuiRender()
{
    ImGui::Begin("Scene Viewport", NULL, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_None);

    ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
    ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);

    if (!m_RendererCreated)
    {
        m_Renderer->Create((int)vWindowSize.x, (int)vWindowSize.y, sf::Color(79, 79, 78));
        m_RendererCreated = true;
    }

    ImGui::Image(*m_Renderer->GetRenderTexture(), sf::Color::White);

    ImGui::End();
}