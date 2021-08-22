#include "ContentBrowser.h"

AutumnEngine::ContentBrowser::ContentBrowser() 
{ 
    m_FolderTexture = std::make_unique<sf::Texture>();
    m_FileTexture = std::make_unique<sf::Texture>();
    m_FileTextTexture = std::make_unique<sf::Texture>();

    if (!m_FolderTexture->loadFromFile("Editor/Style/Icons/FolderIcon.png")) {}
    m_FolderIcon.setTexture(*m_FolderTexture);

    if (!m_FileTexture->loadFromFile("Editor/Style/Icons/FileIcon.png")) {}
    m_FileIcon.setTexture(*m_FileTexture);

    if (!m_FileTextTexture->loadFromFile("Editor/Style/Icons/FileTextIcon.png")) {}
    m_FileTextIcon.setTexture(*m_FileTextTexture);
}
AutumnEngine::ContentBrowser::~ContentBrowser() {}

void AutumnEngine::ContentBrowser::ShowContentBrowser()
{
    ImGui::Begin("Content Browser");

    ImGui::Button("Refresh", ImVec2(100, 20));
    ImGui::SameLine();
    ImGui::Button("New Folder", ImVec2(100, 20));
    ImGui::SameLine();
    ImGui::Button("New File", ImVec2(100, 20));
    ImGui::SameLine();

    ImGui::PushItemWidth(150.f);  
    ImGui::SliderFloat("##Thumbnail Size", &m_ThumbnailSize, 50, 100);
    ImGui::SameLine();
    ImGui::SliderFloat("##Thumbnail Padding", &m_Padding, 10, 20);
    ImGui::SameLine(ImGui::GetWindowWidth() - 150);
    ImGui::InputText("##Search", m_Search, IM_ARRAYSIZE(m_Search));
    ImGui::SameLine(ImGui::GetWindowWidth() - 200);
    ImGui::Text("Search");
    ImGui::PopItemWidth();

    ImGui::Separator();

    if(m_CurrentPath.compare(""))
        ShowLoadedProjectContent();

    ImGui::End();
}

void AutumnEngine::ContentBrowser::ShowLoadedProjectContent()
{
    if (m_CurrentPath != m_DefaultPath)
    {
        if (ImGui::Button("Back", ImVec2(45, 20)))
        {
            m_CurrentPath = m_CurrentPath.parent_path();
        }

        ImGui::Separator();
    }

    m_PanelWidth = ImGui::GetContentRegionAvail().x;
    m_CellSize = m_ThumbnailSize + m_Padding;
    m_ColumnCount = (int)(m_PanelWidth / m_CellSize);
    
    if (m_ColumnCount < 1) m_ColumnCount = 1;

    ImGui::Columns(m_ColumnCount, 0, false);

    for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentPath))
    {
        const auto& path = directoryEntry.path();
        auto relativePath = std::filesystem::relative(path, m_CurrentPath);
        std::string filenameString = relativePath.filename().string();

        if (directoryEntry.is_directory())
        {
            ImGui::ImageButton(m_FolderIcon, { m_ThumbnailSize, m_ThumbnailSize });
            if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
            {
                m_CurrentPath /= path.filename();
            }
        }
        else if (directoryEntry.is_regular_file())
        {
            ImGui::ImageButton(m_FileIcon, { m_ThumbnailSize, m_ThumbnailSize });
            if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
            {
                if (directoryEntry.path().extension() == ".scene")
                {
                    std::cout << "Clicked on a Scene file" << std::endl;

                    if (m_SceneSerializer.GetCurrentLoadedScene().GetSceneFilePath() != directoryEntry.path())
                    {
                        m_SceneSerializer.CreateScene(directoryEntry.path());
                        m_SceneSerializer.DeserializeScene();
                    }
                    else
                    {
                        std::cout << "Scene: " << directoryEntry.path() << " is already loaded!" << std::endl;
                    }
                }
            }
        }

        ImGui::Text(filenameString.c_str());
        ImGui::NextColumn();
    }

    ImGui::Columns(1);
}

void AutumnEngine::ContentBrowser::RefreshDirectory()
{
    // TO BE USED FOR REFRESHING THE FOLDER STRUCTURE SO ITS NOT DOING IT EVERY FRAME
}

void AutumnEngine::ContentBrowser::CreateNewFolder()
{
    // TO BE USED FOR CREATING A NEW FOLDER IN THE CURRENT DIRECTORY
}

void AutumnEngine::ContentBrowser::CreateNewFile()
{
    // TO BE USED FOR CREATING A NEW FILE IN THE CURRENT DIRECTORY
}

void AutumnEngine::ContentBrowser::UpdateProjectPath(std::filesystem::path& projectDirectory)
{
    m_DefaultPath = projectDirectory.string() + "\\" + m_AssetsString.string();
    m_CurrentPath = m_DefaultPath;
}