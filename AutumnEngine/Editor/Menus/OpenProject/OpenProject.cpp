#include "OpenProject.h"

AutumnEngine::OpenProjectMenu::OpenProjectMenu() { m_ShowOpenFileExplorer = false; }
AutumnEngine::OpenProjectMenu::~OpenProjectMenu() {}

void AutumnEngine::OpenProjectMenu::OpenProject(bool& open, AutumnEngine::Console& console, std::filesystem::path* newProjectPath)
{
    ImGui::Begin("Open Project", NULL, ImGuiWindowFlags_NoResize);
    ImGui::SetWindowSize(ImVec2(450, 300));

    ImGui::SameLine(ImGui::GetWindowWidth() - 35);
    if (ImGui::Button("X", ImVec2(30, 20))) { open = !open; }
    ImGui::Text("Project Path");
    ImGui::InputText("##Path", m_ExistingProjectPath, 255);
    ImGui::SameLine();
    
    if (ImGui::Button("Choose Project Path", ImVec2(130, 20)))
    {
        if (!m_ShowOpenFileExplorer)
        {
            m_ShowOpenFileExplorer = true;
        }
    }

    ImGui::Separator();

    if (ImGui::Button("Open", ImVec2(ImGui::GetWindowWidth(), 20)))
    { 
        if ((std::string)m_ExistingProjectPath != "" && std::filesystem::exists(m_ExistingProjectPath))
        {
            *newProjectPath = m_ExistingProjectPath;
            open = !open;
            console.AddMessage(AutumnEngine::MessageType::ACTION, ("Opened Project\n"));
        }
        else
        {
            console.AddMessage(AutumnEngine::MessageType::MESSAGE, "Opening Project, make sure you've specified a valid project path!\n");
        }
    }

    ImGui::End();
}