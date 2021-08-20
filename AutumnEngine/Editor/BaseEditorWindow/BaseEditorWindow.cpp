#include "BaseEditorWindow.h"

AutumnEngine::BaseEditorWindow::BaseEditorWindow()
{
    m_FPS = 0;
    m_Window = nullptr;

    m_ShowHierarchyPanel = true;
    m_ShowInspectorPanel = true;
    m_ShowStatsPanel = true;
    m_ShowAboutWindow = false;
    m_ShowConsole = true;
    m_ShowContentExplorer = true;
    m_ShowSceneViewport = true;
    m_ShowGameViewport = true;
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

    m_Renderer = std::make_unique<AutumnEngine::Renderer>();

    m_SceneViewport.SetRenderer(*m_Renderer);
    m_GameViewport.SetRenderer(*m_Renderer);

    m_Style.SetStyle();
}

void AutumnEngine::BaseEditorWindow::UpdateEditorWindow(sf::Clock deltaTime)
{
    ImGui::SFML::Update(*m_Window, deltaTime.restart());

    m_FPS = 1.f / deltaTime.restart().asSeconds();
    m_FrameTime = 0.1f / m_FPS;

    ImGui::Begin("Editor", 0, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoTitleBar);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

    ImVec2 vWindowSize = ImGui::GetMainViewport()->Size;
    ImVec2 vPos0 = ImGui::GetMainViewport()->Pos;

    ImGui::SetWindowPos(ImVec2((float)vPos0.x, (float)vPos0.y), ImGuiCond_Always);
    ImGui::SetWindowSize(ImVec2((float)vWindowSize.x, (float)vWindowSize.y), ImGuiCond_Always);

    ImGui::PopStyleVar();

    HandleControlButtons();
    HandleMenuBar();
    HandleDockSpace();
    UpdatePanels();

    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ProcessEditorEvents(sf::Event& events)
{
    ImGui::SFML::ProcessEvent(events);
}

void AutumnEngine::BaseEditorWindow::HandleMenuBar()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            ImGui::MenuItem("New Project", NULL, &m_ShowNewProjectPopup);

            ImGui::MenuItem("Open Project", NULL, &m_ShowOpenProjectPopup);

            if (ImGui::MenuItem("Save Project"), NULL) { /* Call Save Project Method */ }
            if (ImGui::MenuItem("Build Project"), NULL) { /* Call Build Project Method */ }
            ImGui::Separator();

            if (ImGui::MenuItem("Create New Scene"), NULL) {}
            if (ImGui::MenuItem("Open Scene"), NULL) {}
            if (ImGui::MenuItem("Save Scene"), NULL) {}
            ImGui::Separator();

            if (ImGui::MenuItem("Exit"), NULL) { ShutDownEditor(); }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Play"), NULL) { /* Call Play Method */ }
            if (ImGui::MenuItem("Pause"), NULL) { /* Call Pause Method */ }
            if (ImGui::MenuItem("Stop"), NULL) { /* Call Pause Method */ }
            ImGui::Separator();
            if (ImGui::MenuItem("Copy"), NULL) { /* Call Copy Method */ }
            if (ImGui::MenuItem("Cut"), NULL) { /* Call Cut Method */ }
            if (ImGui::MenuItem("Paste"), NULL) { /* Call Paste Method */ }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Assets"))
        {
            if (ImGui::BeginMenu("Create"))
            {
                if (ImGui::MenuItem("Create Sprite")) { }
                ImGui::MenuItem("Create Empty Entity");

                ImGui::EndMenu();
            }

            ImGui::Separator();

            ImGui::MenuItem("Show In Explorer", NULL, &m_ShowInExplorer);
            ImGui::MenuItem("Refresh Project", NULL, nullptr);

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Windows"))
        {
            if (ImGui::BeginMenu("Panels"))
            {
                ImGui::MenuItem("Content Explorer", NULL, &m_ShowContentExplorer);
                ImGui::MenuItem("Console", NULL, &m_ShowConsole);
                ImGui::MenuItem("Scene Viewport", NULL, &m_ShowSceneViewport);
                ImGui::MenuItem("Game Viewport", NULL, &m_ShowGameViewport);
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

void AutumnEngine::BaseEditorWindow::HandleControlButtons()
{
    ImGui::SameLine(ImGui::GetWindowWidth() / 2 - 60);
    ImGui::Button("Play", ImVec2(40, 20));
    ImGui::SameLine();
    ImGui::Button("Pause", ImVec2(50, 20));
    ImGui::SameLine();
    ImGui::Button("Stop", ImVec2(40, 20));

    ImGui::Separator();
}

void AutumnEngine::BaseEditorWindow::HandleDockSpace()
{
    m_DockSpaceID = ImGui::GetID("MainDockSpace");
    ImGui::DockSpace(m_DockSpaceID, ImVec2(0.f, 0.f), ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_PassthruCentralNode);
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

    if (m_ShowGameViewport)
        m_GameViewport.ShowGameViewport();

    if (m_ShowNewProjectPopup)
    {
        m_CurrentPath = "";
        m_NewProjectMenu.OpenNewProjectMenu(m_ShowNewProjectPopup, m_Console, &m_CurrentPath);

        if (!m_ShowNewProjectPopup && m_CurrentPath != "")
        {
            std::cout << "Path: " << m_CurrentPath;
            m_ContentBrowser.UpdateProjectPath(m_CurrentPath);
        }
    }
        
    if (m_ShowOpenProjectPopup)
    {
        m_OpenProjectMenu.OpenProject(m_ShowOpenProjectPopup, m_Console, &m_CurrentPath);

        if(!m_ShowOpenProjectPopup && m_CurrentPath != "")
            m_ContentBrowser.UpdateProjectPath(m_CurrentPath);
    }

    if (m_ShowInExplorer)
        OpenProjectInExplorer();
}

void AutumnEngine::BaseEditorWindow::RenderEditor()
{
    ImGui::SFML::Render(*m_Window);
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