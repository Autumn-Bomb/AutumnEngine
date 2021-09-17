#include "../BaseEditorWindow/BaseEditorWindow.h"
#include <time.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

AutumnEngine::BaseEditorWindow m_Editor;

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Autumn Engine");
    window.setFramerateLimit(60);

    m_Editor.SetRenderWindow(window);
    m_Editor.InitialiseEditor();

    sf::Clock deltaClock;
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            m_Editor.ProcessEditorEvents(event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        m_Editor.UpdateEditorWindow(deltaClock);
        ImGui::GetIO().DeltaTime = deltaClock.restart().asSeconds();

        window.clear(sf::Color::White);
        m_Editor.RenderEditor();
        window.display();
    }

    m_Editor.ShutDownEditor();
}