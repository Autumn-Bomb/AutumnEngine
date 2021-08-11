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
        m_Hierarchy.ShowHierarchy();

    if (m_ShowInspectorPanel)
        m_Inspector.ShowInspector();

    if (m_ShowStatsPanel)
        m_Stats.ShowStats(m_FPS, m_FrameTime);

    if (m_ShowAboutWindow)
        m_AboutMenu.ShowAboutMenu(m_ShowAboutWindow);

    if (m_ShowAnimation)
        m_Animation.ShowAnimation();

    if (m_ShowContentExplorer)
        m_ContentBrowser.ShowContentBrowser();

    if (m_ShowProperties)
        m_Properties.ShowProperties();

    if (m_ShowConsole)
        m_Console.ShowConsole();

    if (m_ShowSceneViewport)
        m_SceneViewport.ShowSceneViewport();

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