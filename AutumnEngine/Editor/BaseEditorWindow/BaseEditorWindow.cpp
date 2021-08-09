#include "BaseEditorWindow.h"

AutumnEngine::BaseEditorWindow::BaseEditorWindow()
{
    m_Window = nullptr;

    m_ShowHierarchyPanel = false;
    m_ShowInspectorPanel = false;
    m_ShowStatsPanel = false;
<<<<<<< Updated upstream
=======
    m_ShowAboutWindow = false;
    m_ShowConsole = false;
    m_ShowContentExplorer = false;
    m_ShowSceneViewport = false;
    m_ShowAnimation = false;
    m_ShowProperties = false;
>>>>>>> Stashed changes
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

    m_FPS = 1.f / deltaTime.restart().asSeconds();
    m_FrameTime = m_FPS / 1.f;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin("Editor", 0, ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize);
    ImGui::SetWindowSize(ImVec2(1920, 1080), 0);
    ImGui::SetWindowPos(ImVec2(0, 0));

    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
    ImGui::GetIO().ConfigWindowsResizeFromEdges = false;

    ImGui::StyleColorsDark();
    ImGui::GetStyle().WindowMenuButtonPosition = ImGuiDir_None;
    ImGui::GetStyle().WindowRounding = 0.0f;

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
            if (ImGui::MenuItem("New Project"), "Ctrl+N") { /* Call New Project Method */ }
            if (ImGui::MenuItem("Open Project"), "Ctrl+O") { /* Call Open Project Method */ }
            if (ImGui::MenuItem("Save Project"), "Ctrl+S") { /* Call Save Project Method */ }
            if (ImGui::MenuItem("Build Project"), "Ctrl+B") { /* Call Build Project Method */ }
            ImGui::Separator();

            if (ImGui::MenuItem("Exit"), "Ctrl+W") {  }

<<<<<<< Updated upstream
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
=======
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
            if (ImGui::MenuItem("Create Entity"), "Ctrl+O") { /* Call Create Entity Method */ }
            ImGui::Separator();
            if (ImGui::MenuItem("Show In Explorer"), "Ctrl+S") { /* OpenProjectFolderInExplorer();*/ }
            if (ImGui::MenuItem("Refresh Project"), "Ctrl+F5") { /* Refresh Project */ }
>>>>>>> Stashed changes

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Assets"))
        {
<<<<<<< Updated upstream
            if (ImGui::MenuItem("Create Entity"), "Ctrl+O") { /* Call Create Entity Method */ }
            ImGui::Separator();
            if (ImGui::MenuItem("Show In Explorer"), "Ctrl+S") { /* Open Project Folder In Explorer */ }
            if (ImGui::MenuItem("Refresh Project"), "Ctrl+F5") { /* Refresh Project */ }
=======
            ImGui::MenuItem("About", NULL, &m_ShowAboutWindow);
            ImGui::Separator();
            if (ImGui::MenuItem("Documentation"), "Ctrl+S") { /* Open Documentation */ }
>>>>>>> Stashed changes

            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Window"))
        {
            if (ImGui::BeginMenu("Panels"))
            {
<<<<<<< Updated upstream
                ImGui::MenuItem("Content Explorer");
                ImGui::MenuItem("Console");
                ImGui::MenuItem("Scene Viewport");

                ImGui::MenuItem("Inspector", NULL, &m_ShowInspectorPanel);

                ImGui::MenuItem("Animation");
                ImGui::MenuItem("Properties");
=======
                ImGui::MenuItem("Content Explorer", NULL, &m_ShowContentExplorer);
                ImGui::MenuItem("Console", NULL, &m_ShowConsole);
                ImGui::MenuItem("Scene Viewport", NULL, m_ShowSceneViewport);

                ImGui::MenuItem("Inspector", NULL, &m_ShowInspectorPanel);

                ImGui::MenuItem("Animation", NULL, &m_ShowAnimation);
                ImGui::MenuItem("Properties", NULL, m_ShowProperties);
>>>>>>> Stashed changes

                ImGui::MenuItem("Stats", NULL, &m_ShowStatsPanel);
                ImGui::MenuItem("Scene Hierarchy", NULL, &m_ShowHierarchyPanel);

                ImGui::EndMenu();
            }

            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}

void AutumnEngine::BaseEditorWindow::InitialiseHeirarchy()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Scene Hierarchy");
<<<<<<< Updated upstream
=======

    ImGui::Button("Create", ImVec2(50, 25));
    ImGui::SameLine();
    ImGui::InputText("Search", str0, IM_ARRAYSIZE(str0));
    ImGui::Separator();
>>>>>>> Stashed changes

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::InitialiseInspector()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Inspector");

    ImGui::PopStyleColor();
    ImGui::End();
}
<<<<<<< Updated upstream

void AutumnEngine::BaseEditorWindow::InitialiseStats()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Stats");

    ImGui::Text("FPS: %f", m_FPS);
    ImGui::Text("Frame Time: %f", m_FrameTime);
    ImGui::Text("Entities: %f" , 0);
    ImGui::Text("Batches: %f", 0);
    ImGui::Text("Vertices: %f", 0);

    ImGui::PopStyleColor();
    ImGui::End();
=======

void AutumnEngine::BaseEditorWindow::InitialiseStats()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Stats");

    ImGui::Text("FPS: %i", m_FPS);
    ImGui::Text("Frame Time: %f", m_FrameTime);
    ImGui::Text("Entities: %f" , 0);
    ImGui::Text("Batches: %f", 0);
    ImGui::Text("Vertices: %f", 0);

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::InitialiseConsole()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Console");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::InitialiseAnimation()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Animation");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::InitialiseContentBrowser()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Content Browser");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::InitialiseProperties()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Properties");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();

}

void AutumnEngine::BaseEditorWindow::IntialiseSceneViewport()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Scene Viewport");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowAboutWindow()
{
    ImGui::Begin("About");

    ImGui::Text("Name: Autumn Engine");
    ImGui::Text("Version: 1.0.0");
    ImGui::Text("Description: Autumn Engine is a small 2D Game Engine in development by Autumn Bomb LTD");
    
    if (ImGui::Button("Exit", ImVec2(150, 50))) { m_ShowAboutWindow = !m_ShowAboutWindow; }

    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::UpdatePanels()
{
    if (m_ShowHierarchyPanel)
        InitialiseHeirarchy();

    if (m_ShowInspectorPanel)
        InitialiseInspector();

    if (m_ShowStatsPanel)
        InitialiseStats();

    if (m_ShowAboutWindow)
        ShowAboutWindow();

    if (m_ShowAnimation)
        InitialiseAnimation();

    if (m_ShowContentExplorer)
        InitialiseContentBrowser();
    
    if (m_ShowProperties)
        InitialiseProperties();

    if (m_ShowConsole)
        InitialiseConsole();

    if (m_ShowSceneViewport)
        IntialiseSceneViewport();
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
void AutumnEngine::BaseEditorWindow::UpdatePanels()
{
    if (m_ShowHierarchyPanel)
            InitialiseHeirarchy();

    if (m_ShowInspectorPanel)
            InitialiseInspector();

    if (m_ShowStatsPanel)
            InitialiseStats();
=======
void AutumnEngine::BaseEditorWindow::OpenProjectFolderInExplorer()
{
    std::string currentPath = std::filesystem::path().string();
    const char* path = currentPath.c_str();
    system(path);
>>>>>>> Stashed changes
}