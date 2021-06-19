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
	m_Input = new AutumnEngine::Input();
	m_SceneManager = new AutumnEngine::SceneManager();
	m_GUIManager = new AutumnEngine::GUI();

	// Adds 2 scenes to the "Scene Manager", setting the first scene and then changing it to the second scene
	m_MainMenu = new MainMenu(m_Window, m_Input, m_GUIManager, m_SceneManager);
	m_TestScene = new TestScene(m_Window, m_Input, m_GUIManager);

	m_SceneManager->AddScene(0, "Main Menu", m_MainMenu);
	m_SceneManager->AddScene(1, "Test Scene", m_TestScene);

	m_SceneManager->ChangeScene("Main Menu");
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
			case sf::Event::KeyPressed:
			{
				// Set the key pressed to down
				m_Input->SetKeyDown(m_Event.key.code);
			}
				break;
			case sf::Event::KeyReleased:
			{
				// Set the key pressed to up
				m_Input->SetKeyUp(m_Event.key.code);
			}
				break;
			case sf::Event::MouseMoved:
			{
				// Sets the mouses position to the current position
				m_Input->SetMousePosition(m_Event.mouseMove.x, m_Event.mouseMove.y);
			}
				break;
			case sf::Event::MouseButtonPressed:
			{
				// Sets the left mouse left button to down
				if (m_Event.key.code == sf::Mouse::Left)
					m_Input->SetLeftMouse(AutumnEngine::Input::MouseState::DOWN);

				// Sets the right mouse left button to down
				if (m_Event.key.code == sf::Mouse::Right)
					m_Input->SetRightMouse(AutumnEngine::Input::MouseState::DOWN);
			}
				break;
			case sf::Event::MouseButtonReleased:
			{
				// Sets the left mouse left button to up
				if (m_Event.key.code == sf::Mouse::Left)
					m_Input->SetLeftMouse(AutumnEngine::Input::MouseState::UP);

				// Sets the left mouse left button to up
				if (m_Event.key.code == sf::Mouse::Right)
					m_Input->SetRightMouse(AutumnEngine::Input::MouseState::UP);
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
		m_SceneManager->UpdateScene(m_DeltaTime);
	}
}