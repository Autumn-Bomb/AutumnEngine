#include "NewProject.h"

AutumnEngine::CreateNewProject::CreateNewProject() {}
AutumnEngine::CreateNewProject::~CreateNewProject() {}

void AutumnEngine::CreateNewProject::OpenNewProjectMenu(bool& open, AutumnEngine::Console& console, std::filesystem::path* newProjectPath)
{
    ImGui::Begin("Create a new project", NULL, ImGuiWindowFlags_NoResize);
    ImGui::SetWindowSize(ImVec2(450, 300));

    ImGui::SameLine(ImGui::GetWindowWidth() - 35);
    if (ImGui::Button("X", ImVec2(30, 20))) { open = !open; }
    ImGui::Text("Project Name");
    ImGui::InputText("##Name", m_NewProjectName, 128);
    ImGui::Text("Project Path");
    ImGui::InputText("##Path", m_NewProjectPath, 255);
    ImGui::SameLine();
    ImGui::Button("Choose Path", ImVec2(90, 20));

    ImGui::Separator();

    if (ImGui::Button("Create", ImVec2(ImGui::GetWindowWidth(), 20))) 
    { 
        if (std::string(m_NewProjectName) != "" && std::string(m_NewProjectPath) != "")
        {
            console.AddMessage(AutumnEngine::MessageType::ACTION, ("Created New Project\n"));
            CreateProjectDirectory(console);
            *newProjectPath = (std::string)m_NewProjectPath + "\\" + (std::string)m_NewProjectName;
            open = !open;
        }
        else
        {
            console.AddMessage(AutumnEngine::ERROR, "Creating Project, make sure your project has a path and a name!\n");
        }
    }

    ImGui::End();
}

void AutumnEngine::CreateNewProject::CreateProjectDirectory(AutumnEngine::Console& console)
{
    std::filesystem::create_directory((std::string)m_NewProjectPath + "/" + (std::string)m_NewProjectName);
    std::filesystem::create_directory((std::string)m_NewProjectPath + "/" + (std::string)m_NewProjectName + "/" + "Assets");
    std::filesystem::create_directory((std::string)m_NewProjectPath + "/" + (std::string)m_NewProjectName + "/" + "Build");
    std::filesystem::create_directory((std::string)m_NewProjectPath + "/" + (std::string)m_NewProjectName + "/" + "Library");
    std::filesystem::create_directory((std::string)m_NewProjectPath + "/" + (std::string)m_NewProjectName + "/" + "Project Settings");

    // Creates the .ae project file and the first empty scene for the game
    std::ofstream scene((std::string)m_NewProjectPath + "\\" + (std::string)m_NewProjectName + "/Assets/" + (std::string)m_NewProjectName + ".scene");
}