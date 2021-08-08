#include "../BaseEditorWindow/BaseEditorWindow.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

AutumnEngine::BaseEditorWindow baseWindow;

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "");
    window.setVerticalSyncEnabled(true);

    baseWindow.SetRenderWindow(window);
    baseWindow.InitialiseEditor();

    // let's use char array as buffer, see next part
    // for instructions on using std::string with ImGui
    char windowTitle[255] = "Autumn Engine";

    window.setTitle(windowTitle);
    window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            baseWindow.ProcessEditorEvents(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        baseWindow.UpdateEditorWindow(deltaClock);

        window.clear(sf::Color::White); // fill background with color
        baseWindow.RenderEditor();
        window.display();
    }

    baseWindow.ShutDownEditor();
}