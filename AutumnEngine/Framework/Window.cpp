#include "Window.h"

AutumnEngine::Window::Window() { m_Window = nullptr; }
AutumnEngine::Window::Window(const unsigned int width, const unsigned int height, const char* title, const bool vSync, const bool fullscreen)
{
	// Calls the SetupWindow method passing in the width, height, title of the window and whether vSync is enabled or not
	SetupWindow(width, height, title, vSync, fullscreen);
}
AutumnEngine::Window::~Window(){}

void AutumnEngine::Window::SetupWindow(const unsigned int width, const unsigned int height, const char* title, const bool vSync, const bool fullscreen)
{
	// Initialises the window and enables or disables vSync based on parameter
	fullscreen ? m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Fullscreen) : m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Default);
	m_Window->setVerticalSyncEnabled(vSync);
		
	// Calls the InitialiseGame method to add all scenes to the game
	InitialiseGame();
}

void AutumnEngine::Window::InitialiseGame()
{
	// Adds 2 scenes to the "Scene Manager", setting the first scene and then changing it to the second scene
	m_MainMenu = new MainMenu(m_Window);
	m_TestScene = new TestScene(m_Window);

	m_SceneManager.AddScene(0, "Main Menu", m_MainMenu);
	m_SceneManager.AddScene(1, "Test Scene", m_TestScene);

	m_SceneManager.ChangeScene("Test Scene");
}

void AutumnEngine::Window::HandleWindowEvents()
{
	while (m_Window->pollEvent(m_Event))
	{
		// Switch the current window event type
		switch (m_Event.type)
		{
			// If the event is Window Close
			case sf::Event::Closed:
			{
				// Close the current window
				m_Window->close();
			}
				break;
			// If the event is Window Resized
			case sf::Event::Resized:
			{
				// Set the windows current view to the new size of the window
				m_Window->setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(m_Event.size.width), static_cast<float>(m_Event.size.height))));
			}
				break;
		}
	}
}

void AutumnEngine::Window::RunWindow()
{
	// While the current window is open
	while (m_Window->isOpen())
	{
		// Handle all window events
		HandleWindowEvents();

		m_DeltaTime = m_Clock.restart().asSeconds();
		m_SceneManager.UpdateScene(m_DeltaTime);
	}
}