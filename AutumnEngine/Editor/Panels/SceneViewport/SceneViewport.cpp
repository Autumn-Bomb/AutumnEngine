#include "../SceneViewport/SceneViewport.h"

AutumnEngine::SceneViewport::SceneViewport()
{
    m_Renderer = nullptr;
    m_RendererCreated = false; 
    
    m_MoveIcon = std::make_unique<sf::Texture>();
    m_CursorIcon = std::make_unique<sf::Texture>();

    m_MoveIcon->loadFromFile("Editor/Resources/Icons/Buttons/MoveButton.png");
    m_Move.setTexture(*m_MoveIcon);
    m_CursorIcon->loadFromFile("Editor/Resources/Icons/Buttons/CursorButton.png");
    m_Cursor.setTexture(*m_CursorIcon);
}
AutumnEngine::SceneViewport::~SceneViewport() {}

void AutumnEngine::SceneViewport::ShowSceneViewport()
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
    
    ImGui::SetCursorPos(ImVec2(10, 30));
    ImGui::BeginChild("Tools", ImVec2(100, 45), true, ImGuiWindowFlags_NoResize);
    ImGui::ImageButton(m_Move);
    ImGui::SameLine();
    ImGui::ImageButton(m_Cursor);
    ImGui::EndChild();

    ImGui::End();
}