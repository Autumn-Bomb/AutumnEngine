#include "../BaseEditorWindow/BaseEditorWindow.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

AutumnEngine::BaseEditorWindow m_Editor;

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Autumn Engine (No Project Open)");

    m_Editor.SetRenderWindow(window);
    m_Editor.InitialiseEditor();

    window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    sf::Clock deltaClock;

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            m_Editor.ProcessEditorEvents(event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        m_Editor.UpdateEditorWindow(deltaClock);

        window.clear(sf::Color::White); // fill background with color

        m_Editor.RenderEditor();

        window.display();
    }

    m_Editor.ShutDownEditor();
}