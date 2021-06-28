#include "Application.h"

AutumnEngine::Application::Application() {}
AutumnEngine::Application::~Application() {}

void AutumnEngine::Application::StartApplication()
{
	// Initialises the instance of window and calls its "OpenWindow" function passing in the size, window title, Vsync toggle, fullscreen toggle and FPS lock
	m_Window = AutumnEngine::Window(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, "Autumn Engine", false, false, 60);
	m_Window.RunWindow();
}