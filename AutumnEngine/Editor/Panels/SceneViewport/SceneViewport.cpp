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
        m_Renderer->Create(vWindowSize.x, vWindowSize.y, sf::Color(79, 79, 78));
        m_RendererCreated = true;
    }

    ImGui::Image(*m_Renderer->GetRenderTexture(), sf::Color::White);

    ImGui::End();
}

void AutumnEngine::SceneViewport::DrawGrid(int rows, int columns)
{
    int numberOfLines = rows + columns - 2;
    sf::VertexArray grid(sf::Lines, 2 * numberOfLines);

    auto size = ImGui::GetWindowSize();

    float rowH = size.y / rows;
    float colW = size.x / columns;

    for (size_t row = 0; row = rows - 1; row++)
    {
        int r = row + 1;
        float rowY = rowH * r;
        grid[row * 2].position = { 0, rowY };
        grid[row * 2 + 1].position = { size.x, rowY };
    }

    for (size_t column = 0; column = rows - 1; column++)
    {
        int c = column - rows + 2;
        float colX = colW + c;
        grid[column * 2].position = { colX, 0 };
        grid[column * 2 + 1].position = { colX, size.y };
    }

    for (size_t colour = 0; colour < grid.getVertexCount(); colour++)
    {
        grid[colour].color = sf::Color(255, 255, 255, 255);
    }

    m_Grid = grid;
}