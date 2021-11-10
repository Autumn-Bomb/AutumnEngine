#include "BaseEditorWindow.h"

AutumnEngine::BaseEditorWindow::BaseEditorWindow()
{   
    m_Window = nullptr;

    m_ShowNewProjectPopup = false;
    m_ShowOpenProjectPopup = false;
}
AutumnEngine::BaseEditorWindow::~BaseEditorWindow() {}

void AutumnEngine::BaseEditorWindow::InitialiseEditor()
{
    ImGui::SFML::Init(*m_Window);
    ImGui::GetIO().ConfigFlags = ImGuiConfigFlags_DockingEnable;

    m_Style = AutumnEngine::Style(ImGui::GetStyle());

    m_SceneViewport.SetRenderer(m_Renderer);
    m_GameViewport.SetRenderer(m_Renderer);

    m_EditorSettings.SetContentBroswer(&m_ContentBrowser);
    m_EditorSettings.SetStyle(&m_Style);
    
    //m_EditorSettings.ApplyLastStyle();

    m_PanelManager.AddPanel("Console", &m_Console);
    m_PanelManager.AddPanel("Animation", &m_Animation);
    m_PanelManager.AddPanel("Content Browser", &m_ContentBrowser);
    m_PanelManager.AddPanel("Game Viewport", &m_GameViewport);
    m_PanelManager.AddPanel("Hierarchy", &m_Hierarchy);
    m_PanelManager.AddPanel("Inspector", &m_Inspector);
    m_PanelManager.AddPanel("Scene Viewport", &m_SceneViewport);
    m_PanelManager.AddPanel("Profiler", &m_Profiler);

    m_PanelManager.AddPanel("About", &m_AboutMenu);
    m_PanelManager.AddPanel("Editor Settings", &m_EditorSettings);

    LoadEditorIcons();
}

void AutumnEngine::BaseEditorWindow::LoadEditorIcons()
{
    m_PlayButtonTexture = std::make_unique<sf::Texture>();
    if (!m_PlayButtonTexture->loadFromFile("Editor/Resources/Icons/Buttons/PlayButton.png")) {}
    m_PlayButtonIcon.setTexture(*m_PlayButtonTexture);

    m_PauseButtonTexture = std::make_unique<sf::Texture>();
    if (!m_PauseButtonTexture->loadFromFile("Editor/Resources/Icons/Buttons/PauseButton.png")) {}
    m_PauseButtonIcon.setTexture(*m_PauseButtonTexture);

    m_StopButtonTexture = std::make_unique<sf::Texture>();
    if (!m_StopButtonTexture->loadFromFile("Editor/Resources/Icons/Buttons/StopButton.png")) {}
    m_StopButtonIcon.setTexture(*m_StopButtonTexture);
}

void AutumnEngine::BaseEditorWindow::UpdateEditorWindow(sf::Clock& deltaTime)
{
    ImGui::SFML::Update(*m_Window, deltaTime.restart());

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
            if (ImGui::MenuItem("Unload Project")) { }

            if (ImGui::MenuItem("Save Project"), NULL) { /* Call Save Project Method */ }
            if (ImGui::MenuItem("Build Project"), NULL) { /* Call Build Project Method */ }
            ImGui::Separator();

            if (ImGui::MenuItem("New Scene"), NULL) {}
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
            ImGui::Separator();

            ImGui::MenuItem("Editor Settings", NULL, &m_PanelManager.GetPanel("Editor Settings").GetActiveState());
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

            ImGui::MenuItem("Refresh Project", NULL, nullptr);

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Windows"))
        {
            if (ImGui::BeginMenu("Panels"))
            {
                ImGui::MenuItem("Content Explorer", NULL, &m_PanelManager.GetPanel("Content Browser").GetActiveState());
                ImGui::MenuItem("Console", NULL, &m_PanelManager.GetPanel("Console").GetActiveState());
                ImGui::MenuItem("Scene Viewport", NULL, &m_PanelManager.GetPanel("Scene Viewport").GetActiveState());
                ImGui::MenuItem("Game Viewport", NULL, &m_PanelManager.GetPanel("Game Viewport").GetActiveState());
                ImGui::MenuItem("Inspector", NULL, &m_PanelManager.GetPanel("Inspector").GetActiveState());
                ImGui::MenuItem("Animation", NULL, &m_PanelManager.GetPanel("Animation").GetActiveState());
                ImGui::MenuItem("Profiler", NULL, &m_PanelManager.GetPanel("Profiler").GetActiveState());
                ImGui::MenuItem("Scene Hierarchy", NULL, &m_PanelManager.GetPanel("Hierarchy").GetActiveState());

                ImGui::EndMenu();
            }

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Help"))
        {
            ImGui::MenuItem("About", NULL, &m_PanelManager.GetPanel("About").GetActiveState());
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
    ImGui::ImageButton(m_PlayButtonIcon);
    ImGui::SameLine();
    ImGui::ImageButton(m_PauseButtonIcon);
    ImGui::SameLine();
    ImGui::ImageButton(m_StopButtonIcon);

    ImGui::Separator();
}

void AutumnEngine::BaseEditorWindow::HandleDockSpace()
{
    m_DockSpaceID = ImGui::GetID("MainDockSpace");
    ImGui::DockSpace(m_DockSpaceID, ImVec2(0.f, 0.f), ImGuiDockNodeFlags_None | ImGuiDockNodeFlags_PassthruCentralNode);
}

void AutumnEngine::BaseEditorWindow::UpdatePanels()
{
    if (m_ShowNewProjectPopup)
    {
        m_CurrentPath = "";
        m_NewProjectMenu.OpenNewProjectMenu(m_ShowNewProjectPopup, m_Console, &m_CurrentPath);

        if (!m_ShowNewProjectPopup && m_CurrentPath.compare(""))
            m_ContentBrowser.UpdateProjectPath(m_CurrentPath);
    }
    
    if (m_ShowOpenProjectPopup)
    {
        m_CurrentPath = "";
        m_OpenProjectMenu.OpenProject(m_ShowOpenProjectPopup, m_Console, &m_CurrentPath);

        if(!m_ShowOpenProjectPopup && m_CurrentPath.compare(""))
            m_ContentBrowser.UpdateProjectPath(m_CurrentPath);
    }

    m_PanelManager.ShowPanels();
}

void AutumnEngine::BaseEditorWindow::RenderEditor()
{
    ImGui::SFML::Render(*m_Window);
}

void AutumnEngine::BaseEditorWindow::ShutDownEditor()
{
    ImGui::SFML::Shutdown();
    m_Window->close();
}