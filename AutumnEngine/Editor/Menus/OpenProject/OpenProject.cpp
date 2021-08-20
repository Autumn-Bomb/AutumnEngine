#include "OpenProject.h"

AutumnEngine::OpenProjectMenu::OpenProjectMenu() {}
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
    ImGui::Button("Choose Project Path", ImVec2(130, 20));

    ImGui::Separator();

    if (ImGui::Button("Open", ImVec2(ImGui::GetWindowWidth(), 20)))
    { 
        if ((std::string)m_ExistingProjectPath != "")
        {
            console.AddMessage(AutumnEngine::MessageType::ACTION, ("Opened Project\n"));
            *newProjectPath = m_ExistingProjectPath;
            open = !open;
        }
        else
        {
            console.AddMessage(AutumnEngine::MessageType::ERROR, "Opening Project, make sure you've specified a project path!\n");
        }
    }

    ImGui::End();
}