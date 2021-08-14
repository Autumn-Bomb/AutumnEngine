#include "../GameViewport/GameViewport.h"

AutumnEngine::GameViewport::GameViewport() {}
AutumnEngine::GameViewport::~GameViewport() {}

void AutumnEngine::GameViewport::ShowGameViewport()
{
    ImGui::Begin("Game Viewport", NULL, ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoScrollbar);

    ImGui::Image(*m_Renderer->GetRenderTexture(), sf::Color::White);

    ImGui::End();
}