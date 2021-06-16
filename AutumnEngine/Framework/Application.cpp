#include "Application.h"

AutumnEngine::Application::Application() {}
AutumnEngine::Application::~Application(){}

void AutumnEngine::Application::StartApplication()
{
	// Initialises the instance of window and calls its "OpenWindow" function passing in the size, window title, Vsync toggle and fullscreen toggle
	m_Window = AutumnEngine::Window(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, "Autumn Engine", true, true);
	m_Window.RunWindow();
}