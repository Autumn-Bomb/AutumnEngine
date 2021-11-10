#include "../BaseEditorWindow/BaseEditorWindow.h"

AutumnEngine::BaseEditorWindow m_Editor;

int main()
{
    srand(time(NULL));

    sf::RenderWindow m_RenderWindow = sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Autumn Engine");
    m_Editor.SetRenderWindow(&m_RenderWindow);
    m_Editor.InitialiseEditor();
    m_RenderWindow.setFramerateLimit(60);

    sf::Clock deltaClock;
    sf::Event event;

    while (m_RenderWindow.isOpen())
    {
        while (m_RenderWindow.pollEvent(event))
        {
            m_Editor.ProcessEditorEvents(event);

            if (event.type == sf::Event::Closed)
            {
                m_RenderWindow.close();
            }
        }

        m_Editor.UpdateEditorWindow(deltaClock);
        ImGui::GetIO().DeltaTime = deltaClock.restart().asSeconds();

        m_RenderWindow.clear(sf::Color::White);
        m_Editor.RenderEditor();
        m_RenderWindow.display();
    }

    m_Editor.ShutDownEditor();
}