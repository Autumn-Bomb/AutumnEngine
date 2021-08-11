#include "BaseEditorWindow.h"

AutumnEngine::BaseEditorWindow::BaseEditorWindow()
{
    m_Window = nullptr;

    m_ShowHierarchyPanel = true;
    m_ShowInspectorPanel = true;
    m_ShowStatsPanel = true;
    m_ShowAboutWindow = false;
    m_ShowConsole = true;
    m_ShowContentExplorer = true;
    m_ShowSceneViewport = true;
    m_ShowAnimation = true;
    m_ShowProperties = true;
    m_ShowAnimation = false;
    m_ShowProperties = true;

    m_ShowNewProjectPopup = false;
    m_ShowInExplorer = false;
}
AutumnEngine::BaseEditorWindow::~BaseEditorWindow() {}

void AutumnEngine::BaseEditorWindow::InitialiseEditor()
{
    ImGui::SFML::Init(*m_Window);
    ImGui::GetIO().ConfigFlags = ImGuiConfigFlags_DockingEnable;
    m_CurrentPath = std::filesystem::current_path();
}

void AutumnEngine::BaseEditorWindow::ProcessEditorEvents(sf::Event& events)
{
    ImGui::SFML::ProcessEvent(events);
}

void AutumnEngine::BaseEditorWindow::UpdateEditorWindow(sf::Clock deltaTime)
{
    ImGui::SFML::Update(*m_Window, deltaTime.restart());

    m_FPS = 1.f / deltaTime.restart().asSeconds();
    m_FrameTime = 0.1f / m_FPS;

    ImGui::Begin("Editor", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

    ImGui::SetWindowSize(ImVec2(1920, 1080), 0);
    ImGui::SetWindowPos(ImVec2(0, 0));

    ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
    ImVec2 vPos0 = ImGui::GetMainViewport()->Pos;

    ImGui::SetWindowPos(ImVec2((float)vPos0.x, (float)vPos0.y), ImGuiCond_Always);
    ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);

    ImGui::StyleColorsDark();
    ImGui::GetStyle().WindowMenuButtonPosition = ImGuiDir_None;
    ImGui::GetStyle().WindowRounding = 0.f;

    ImGui::PopStyleVar();

    HandleMenuBar();
    UpdatePanels();

    ImGui::End(); // end window
}

void AutumnEngine::BaseEditorWindow::HandleMenuBar()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            ImGui::MenuItem("New Project", "Ctrl+N", &m_ShowNewProjectPopup);

            if (ImGui::MenuItem("Open Project"), "Ctrl+O") { /* Call Open Project Method */ }
            if (ImGui::MenuItem("Save Project"), "Ctrl+S") { /* Call Save Project Method */ }
            if (ImGui::MenuItem("Build Project"), "Ctrl+B") { /* Call Build Project Method */ }
            ImGui::Separator();

            if (ImGui::MenuItem("Exit"), "Ctrl+W") {}

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Play"), "Ctrl+P") { /* Call Play Method */ }
            if (ImGui::MenuItem("Pause"), "Ctrl+P") { /* Call Pause Method */ }
            ImGui::Separator();
            if (ImGui::MenuItem("Copy"), "Ctrl+C") { /* Call Copy Method */ }
            if (ImGui::MenuItem("Cut"), "Ctrl+X") { /* Call Cut Method */ }
            if (ImGui::MenuItem("Paste"), "Ctrl+V") { /* Call Paste Method */ }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Assets"))
        {
            if (ImGui::BeginMenu("Create"))
            {
                ImGui::MenuItem("Create Empty Entity");
                ImGui::MenuItem("Create Sprite");

                ImGui::EndMenu();
            }

            ImGui::Separator();

            ImGui::MenuItem("Show In Explorer", "Ctrl+S", &m_ShowInExplorer);
            ImGui::MenuItem("Refresh Project", "Ctrl+F5", nullptr);

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Windows"))
        {
            if (ImGui::BeginMenu("Panels"))
            {
                ImGui::MenuItem("Content Explorer", NULL, &m_ShowContentExplorer);

                ImGui::MenuItem("Console", NULL, &m_ShowConsole);

                ImGui::MenuItem("Scene Viewport", NULL, &m_ShowSceneViewport);

                ImGui::MenuItem("Inspector", NULL, &m_ShowInspectorPanel);

                ImGui::MenuItem("Animation", NULL, &m_ShowAnimation);
                ImGui::MenuItem("Properties", NULL, &m_ShowProperties);

                ImGui::MenuItem("Stats", NULL, &m_ShowStatsPanel);
                ImGui::MenuItem("Scene Hierarchy", NULL, &m_ShowHierarchyPanel);

                ImGui::EndMenu();
            }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help"))
        {
            ImGui::MenuItem("About", NULL, &m_ShowAboutWindow);
            ImGui::Separator();
            if (ImGui::MenuItem("Scripting Reference"), "Ctrl+S") { /* Open Documentation */ }
            if (ImGui::MenuItem("Documentation"), "Ctrl+S") { /* Open Documentation */ }

            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

void AutumnEngine::BaseEditorWindow::ShowHeirarchy()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Scene Hierarchy");

    ImGui::Button("Create", ImVec2(50, 18));
    ImGui::SameLine();
    ImGui::InputText("", m_Search, IM_ARRAYSIZE(m_Search));
    ImGui::Separator();

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowInspector()
{
     ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
     ImGui::Begin("Inspector");

     ImGui::Button("Add Component", ImVec2(ImGui::GetWindowSize().x - 10.f, 30.f));

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowStats()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Stats");

    ImGui::Text("FPS: %i", m_FPS);
    ImGui::Text("Frame Time: %f", m_FrameTime);

    ImGui::Text("Entities: %f", 0);
    ImGui::Text("Batches: %f", 0);
    ImGui::Text("Vertices: %f", 0);

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowAnimation()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Animation");

    ImGui::Text("Animation Name:");

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowContentBrowser()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Content Browser");

    // INSERT CONTENT HERE
    ImGui::Button("Back", ImVec2(45, 20));
    ImGui::SameLine();
    ImGui::Text("Path: ");

    ImGui::Separator();

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowProperties()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Properties");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowSceneViewport()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Scene Viewport");

    ImGui::SameLine(ImGui::GetWindowWidth() / 2 - 60);
    ImGui::Button("Play", ImVec2(40, 20));
    ImGui::SameLine();
    ImGui::Button("Pause", ImVec2(40, 20));
    ImGui::SameLine();
    ImGui::Button("Stop", ImVec2(40, 20));

    ImGui::Separator();

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowAboutWindow()
{
    ImGui::Begin("About");

    ImGui::Text("Name: Autumn Engine");
    ImGui::Text("Version: 1.0.0");
    ImGui::Text("Description: Autumn Engine is a small 2D Game Engine in development by Autumn Bomb LTD");
    ImGui::Text("The Team");
    ImGui::Indent();
    ImGui::BulletText("Daniel Martin - Lead Programmer");
    ImGui::BulletText("Aaron Gray - Lead Designer");
    ImGui::Unindent();

    if (ImGui::Button("Exit", ImVec2(150, 50))) { m_ShowAboutWindow = !m_ShowAboutWindow; }

    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::RenderEditor()
{
    ImGui::SFML::Render(*m_Window);
}

void AutumnEngine::BaseEditorWindow::MakeNewProject()
{
    ImGui::Begin("Create a new project", NULL, ImGuiWindowFlags_NoResize);
    ImGui::SetWindowSize(ImVec2(450, 300));

    ImGui::SameLine(ImGui::GetWindowWidth() - 35);
    if (ImGui::Button("X", ImVec2(30, 20))) { m_ShowNewProjectPopup = !m_ShowNewProjectPopup; }
    ImGui::Text("Project Name");
    ImGui::InputText("##Name", m_NewProjectName, IM_ARRAYSIZE(m_NewProjectName));
    ImGui::Text("Project Path");
    ImGui::InputText("##Path", m_NewProjectPath, IM_ARRAYSIZE(m_NewProjectPath));

    ImGui::Separator();

    if (ImGui::Button("Create", ImVec2(ImGui::GetWindowWidth(), 20))) { m_Console.AddMessage(AutumnEngine::MessageType::MESSAGE, "Created New Project\n"); m_ShowNewProjectPopup = !m_ShowNewProjectPopup; }

    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::UpdatePanels()
{
    if (m_ShowHierarchyPanel)
        ShowHeirarchy();

    if (m_ShowInspectorPanel)
        ShowInspector();

    if (m_ShowStatsPanel)
        ShowStats();

    if (m_ShowAboutWindow)
        ShowAboutWindow();

    if (m_ShowAnimation)
        ShowAnimation();

    if (m_ShowContentExplorer)
        ShowContentBrowser();

    if (m_ShowProperties)
        ShowProperties();

    if (m_ShowConsole)
        m_Console.ShowConsole();

    if (m_ShowSceneViewport)
        ShowSceneViewport();

    if (m_ShowInExplorer)
        OpenProjectInExplorer();

    if (m_ShowNewProjectPopup)
        MakeNewProject();
}

void AutumnEngine::BaseEditorWindow::OpenProjectInExplorer()
{
    ShellExecute(NULL, "OPEN", "EXPLORER.EXE", m_CurrentPath.string().c_str(), NULL, 1);
    m_ShowInExplorer = false;
}

void AutumnEngine::BaseEditorWindow::ShutDownEditor()
{
    ImGui::SFML::Shutdown();
}