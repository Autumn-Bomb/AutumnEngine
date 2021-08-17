#include "ContentBrowser.h"

AutumnEngine::ContentBrowser::ContentBrowser() {}
AutumnEngine::ContentBrowser::ContentBrowser(std::filesystem::path& projectDirectory) 
{ 
    m_DefaultPath = projectDirectory.string() + m_AssetsString.string(); 
    m_CurrentPath = m_DefaultPath; 

    m_FolderTexture = std::make_unique<sf::Texture>();

    if (!m_FolderTexture->loadFromFile("Editor/Style/Icons/FolderIcon.png")) {}

    m_FolderIcon.setTexture(*m_FolderTexture);
}
AutumnEngine::ContentBrowser::~ContentBrowser() {}

void AutumnEngine::ContentBrowser::ShowContentBrowser()
{
    ImGui::Begin("Content Browser");

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

    for (auto& directoryEntry : std::filesystem::directory_iterator(m_CurrentPath))
    {
        const auto& path = directoryEntry.path();
        auto relativePath = std::filesystem::relative(m_CurrentPath, m_AssetsString);
        std::string filenameString = path.string();

        if (directoryEntry.is_directory())
        {
            //ImGui::SameLine();
            if(ImGui::Button(filenameString.c_str()))
            {
                m_CurrentPath /= path.filename();
            }
        }
        else
        {
            if (ImGui::Button(filenameString.c_str())) {}
        }
    }
}