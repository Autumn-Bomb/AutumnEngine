#include "../GameViewport/GameViewport.h"

AutumnEngine::GameViewport::GameViewport() { m_Renderer = nullptr; }
AutumnEngine::GameViewport::~GameViewport() {}

void AutumnEngine::GameViewport::OnImGuiRender()
{
    ImGui::Begin("Game Viewport", NULL, ImGuiWindowFlags_NoScrollbar);

    ImGui::Image(*m_Renderer->GetRenderTexture(), sf::Color::White);

    ImGui::End();
}