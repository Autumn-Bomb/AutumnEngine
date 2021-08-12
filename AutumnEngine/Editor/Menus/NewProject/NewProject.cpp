#include "NewProject.h"

AutumnEngine::CreateNewProject::CreateNewProject() {}
AutumnEngine::CreateNewProject::~CreateNewProject() {}

void AutumnEngine::CreateNewProject::OpenNewProjectMenu(bool& open, AutumnEngine::Console& console)
{
    ImGui::Begin("Create a new project", NULL, ImGuiWindowFlags_NoResize);
    ImGui::SetWindowSize(ImVec2(450, 300));

    ImGui::SameLine(ImGui::GetWindowWidth() - 35);
    if (ImGui::Button("X", ImVec2(30, 20))) { open = !open; }
    ImGui::Text("Project Name");
    ImGui::InputText("##Name", m_NewProjectName, IM_ARRAYSIZE(m_NewProjectName));
    ImGui::Text("Project Path");
    ImGui::InputText("##Path", m_NewProjectPath, IM_ARRAYSIZE(m_NewProjectPath));
    ImGui::SameLine();
    ImGui::Button("Choose Path", ImVec2(90, 20));

    ImGui::Separator();

    if (ImGui::Button("Create", ImVec2(ImGui::GetWindowWidth(), 20))) { console.AddMessage(AutumnEngine::MessageType::ACTION, "Created New Project\n"); CreateProjectDirectory(console); open = !open; }

    ImGui::End();
}

void AutumnEngine::CreateNewProject::CreateProjectDirectory(AutumnEngine::Console& console)
{
    console.AddMessage(AutumnEngine::MessageType::MESSAGE, "Project name: \n");
    console.AddMessage(AutumnEngine::MessageType::MESSAGE, "Project Directory: \n");
}