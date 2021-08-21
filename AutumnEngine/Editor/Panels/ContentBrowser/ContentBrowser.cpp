#include "ContentBrowser.h"

AutumnEngine::ContentBrowser::ContentBrowser() 
{ 
    m_FolderTexture = std::make_unique<sf::Texture>();

    if (!m_FolderTexture->loadFromFile("Editor/Style/Icons/FolderIcon.png")) {}
    m_FolderIcon.setTexture(*m_FolderTexture);
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
    ImGui::InputText("##Search", m_Search, IM_ARRAYSIZE(m_Search));
    ImGui::SameLine();
    ImGui::SliderFloat("Thumbnail Size", &m_ThumbnailSize, 50, 100);
    ImGui::SameLine();
    ImGui::SliderFloat("Thumbnail Padding", &m_Padding, 10, 100);
    ImGui::PopItemWidth();

    ImGui::Separator();

    if(m_CurrentPath != "")
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

        ImGui::ImageButton(m_FolderIcon, { m_ThumbnailSize, m_ThumbnailSize });
        if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
        {
            if (directoryEntry.is_directory())
            {
                m_CurrentPath /= path.filename();
            }
            else if (directoryEntry.path().extension() == ".scene")
            {
                // DESIRALIZE SCENE
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