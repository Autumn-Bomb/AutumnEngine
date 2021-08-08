#include "BaseEditorWindow.h"

AutumnEngine::BaseEditorWindow::BaseEditorWindow()
{
    m_Window = nullptr;
}
AutumnEngine::BaseEditorWindow::~BaseEditorWindow(){}

void AutumnEngine::BaseEditorWindow::InitialiseEditor()
{
	ImGui::SFML::Init(*m_Window);
}

void AutumnEngine::BaseEditorWindow::ProcessEditorEvents(sf::Event& events)
{
	ImGui::SFML::ProcessEvent(events);
}

void AutumnEngine::BaseEditorWindow::UpdateEditorWindow(sf::Clock deltaTime)
{
    ImGui::SFML::Update(*m_Window, deltaTime.restart());

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin("Editor", 0, ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(1920, 1080), 0);
    ImGui::SetWindowPos(ImVec2(0, 0));
    ImGui::GetStyle().WindowRounding = 0.0f;
    ImGui::PopStyleVar();

    HandleMenuBar();
    InitialiseHeirarchy();
    InitialiseInspector();

    ImGui::End(); // end window
}

void AutumnEngine::BaseEditorWindow::HandleMenuBar()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open"), "Ctrl+O") { /* Run Open Dialogue */ }
            if (ImGui::MenuItem("Save"), "Ctrl+S") { /* Run Save Dialogue */ }
            if (ImGui::MenuItem("Exit"), "Ctrl+W") { /* ShutDownEditor(); */ }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Settings"))
        {
            if (ImGui::MenuItem("Open"), "Ctrl+O") { /* Run Open Dialogue */ }
            if (ImGui::MenuItem("Save"), "Ctrl+S") { /* Run Save Dialogue */ }
            if (ImGui::MenuItem("Close"), "Ctrl+W") { /* Close Editor */ }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help"))
        {
            if (ImGui::MenuItem("Open"), "Ctrl+O") { /* Run Open Dialogue */ }
            if (ImGui::MenuItem("Save"), "Ctrl+S") { /* Run Save Dialogue */ }
            if (ImGui::MenuItem("Close"), "Ctrl+W") { /* Close Editor */ }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("About"))
        {
            if (ImGui::MenuItem("Open"), "Ctrl+O") { /* Run Open Dialogue */ }
            if (ImGui::MenuItem("Save"), "Ctrl+S") { /* Run Save Dialogue */ }
            if (ImGui::MenuItem("Close"), "Ctrl+W") { /* Close Editor */ }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

void AutumnEngine::BaseEditorWindow::InitialiseHeirarchy()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::BeginChild("Heirarchy", ImVec2(250, 1080), true);

    ImGui::SetWindowPos(ImVec2(0, 0));

    ImGui::GetWindowDrawList()->AddRect(ImVec2(0, 0), ImVec2(250, 55), ImColor(255, 255, 255, 255), 0.0f, 1);
    ImGui::GetWindowDrawList()->AddText(ImVec2(100.f, 40.f), ImColor(255, 255, 255, 255), "Heirarchy");

    ImGui::PopStyleColor();
    ImGui::EndChild();
}

void AutumnEngine::BaseEditorWindow::InitialiseInspector()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::BeginChild("Inspector", ImVec2(250, 1080), true);

    ImGui::SetWindowPos(ImVec2(830, 0));

    ImGui::GetWindowDrawList()->AddRect(ImVec2(0, 0), ImVec2(250, 55), ImColor(255, 255, 255, 255), 0.0f, 1);
    ImGui::GetWindowDrawList()->AddText(ImVec2(100.f, 40.f), ImColor(255, 255, 255, 255), "Inspector");

    ImGui::PopStyleColor();
    ImGui::EndChild();
}

void AutumnEngine::BaseEditorWindow::RenderEditor()
{
    ImGui::SFML::Render(*m_Window);
}

void AutumnEngine::BaseEditorWindow::ShutDownEditor()
{
    m_Window->close();
    ImGui::SFML::Shutdown();
}