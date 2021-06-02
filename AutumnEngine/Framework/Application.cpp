#include "Application.h"

AutumnEngine::Application::Application() {}
AutumnEngine::Application::~Application(){}

void AutumnEngine::Application::StartApplication()
{
	// Initialises the instance of window and calls its "OpenWindow" function
	m_Window = AutumnEngine::Window(1024, 768, "Autumn Engine", false);
	m_Window.OpenWindow();
}