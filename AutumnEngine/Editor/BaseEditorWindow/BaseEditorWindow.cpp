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
}
AutumnEngine::BaseEditorWindow::~BaseEditorWindow(){}

void AutumnEngine::BaseEditorWindow::InitialiseEditor()
{
	ImGui::SFML::Init(*m_Window);
    ImGui::GetIO().ConfigFlags = ImGuiConfigFlags_DockingEnable;
}

void AutumnEngine::BaseEditorWindow::ProcessEditorEvents(sf::Event& events)
{
	ImGui::SFML::ProcessEvent(events);
}

void AutumnEngine::BaseEditorWindow::UpdateEditorWindow(sf::Clock deltaTime)
{
    ImGui::SFML::Update(*m_Window, deltaTime.restart());

    m_FPS = 1.f / deltaTime.restart().asSeconds();
    m_FrameTime = 1.0f / m_FPS;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::Begin("Editor", 0, ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoMove | ImGuiWindowFlags_::ImGuiWindowFlags_NoBringToFrontOnFocus);

    ImGui::SetWindowSize(ImVec2(1920, 1080), 0);
    ImGui::SetWindowPos(ImVec2(0, 0));

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
            if (ImGui::MenuItem("Show In Explorer"), "Ctrl+S") {  OpenProjectInExplorer(); }
            if (ImGui::MenuItem("Refresh Project"), "Ctrl+F5") { /* Refresh Project */ }

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

    ImGui::Button("Create", ImVec2(50, 25));
    ImGui::SameLine();
    ImGui::InputText("Search", str0, IM_ARRAYSIZE(str0));
    ImGui::Separator();

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowInspector()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Inspector");

    if (ImGui::Button("Add Component", ImVec2(ImGui::GetWindowWidth(), 20)))
    {
        m_Console.AddMessage(AutumnEngine::MessageType::MESSAGE, " ADDING COMPONENT \n");
    }

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowStats()
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

void AutumnEngine::BaseEditorWindow::ShowConsole()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Console");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowAnimation()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Animation");

    // INSERT CONTENT HERE

    ImGui::PopStyleColor();
    ImGui::End();
}

void AutumnEngine::BaseEditorWindow::ShowContentBrowser()
{
    ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
    ImGui::Begin("Content Browser");

    // INSERT CONTENT HERE

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

    ImGui::SameLine(ImGui::GetWindowWidth() - 700);
    ImGui::Button("Play");
    ImGui::SameLine();
    ImGui::Button("Pause");
    ImGui::SameLine();
    ImGui::Button("Stop");

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
    
    if (ImGui::Button("Exit", ImVec2(150, 50))) { m_ShowAboutWindow = !m_ShowAboutWindow; }

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
}

void AutumnEngine::BaseEditorWindow::RenderEditor()
{
    ImGui::SFML::Render(*m_Window);
}

void AutumnEngine::BaseEditorWindow::OpenProjectInExplorer()
{
    std::filesystem::path currentPath = std::filesystem::current_path();
    ShellExecute(NULL, "Open", "Explorer.exe", currentPath.string().c_str(), NULL, NULL);
}

void AutumnEngine::BaseEditorWindow::ShutDownEditor()
{
    ImGui::SFML::Shutdown();
}