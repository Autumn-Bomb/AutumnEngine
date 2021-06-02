#include "Window.h"

AutumnEngine::Window::Window() { m_Window = nullptr; }
AutumnEngine::Window::Window(const unsigned int width, const unsigned int height, const char* title, const bool vSync)
{
	// Calls the SetupWindow method passing in the width, height, title of the window and whether vSync is enabled or not
	SetupWindow(width, height, title, vSync);
}
AutumnEngine::Window::~Window(){}

void AutumnEngine::Window::SetupWindow(const unsigned int width, const unsigned int height, const char* title, const bool vSync)
{
	// Initialises the window and enables or disables vSync based on parameter
	m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	m_Window->setVerticalSyncEnabled(vSync);
		
	InitialiseScenes();
}

void AutumnEngine::Window::InitialiseScenes()
{
	// Adds 2 scenes to the "Scene Manager", setting the first scene and then changing it to the second scene
	m_MainMenu = new MainMenu(m_Window);
	m_TestScene = new TestScene(m_Window);

	m_SceneManager.AddScene(0, "Main Menu", m_MainMenu);
	m_SceneManager.AddScene(1, "Test Scene", m_TestScene);

	m_SceneManager.ChangeScene("Test Scene");
}

void AutumnEngine::Window::WindowEvents()
{
	while (m_Window->pollEvent(m_Event))
	{
		// Switch the current window event type
		switch (m_Event.type)
		{
			// If the event is close
			case sf::Event::Closed:
			{
				// Close the current window
				m_Window->close();
			}
				break;
			// If the event is Resized
			case sf::Event::Resized:
			{
				// Set the windows current view to the new size of the window
				m_Window->setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(m_Event.size.width), static_cast<float>(m_Event.size.height))));
			}
				break;
		}
	}
}

void AutumnEngine::Window::OpenWindow()
{
	sf::Clock clock;
	float currentTime;

	// While the current window is open
	while (m_Window->isOpen())
	{
		// Handle all window events
		WindowEvents();

		currentTime = clock.restart().asSeconds();
		m_SceneManager.UpdateScene(currentTime);
	}
}