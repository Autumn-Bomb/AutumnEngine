#include "Window.h"

AutumnEngine::Window::Window()
{
	// Initialise default values should the overloaded Constructor not be called
	m_Window = nullptr;
	m_DeltaTime = 0; 
	m_Event = sf::Event(); 
}
AutumnEngine::Window::Window(unsigned int width, unsigned int height, std::string title, bool vSync, bool fullscreen)
{
	// Calls the SetupWindow function passing in the width, height, title of the window, whether vSync is enabled or not and maxFPS
	SetupWindow(width, height, title, vSync, fullscreen);
}
AutumnEngine::Window::~Window(){}

void AutumnEngine::Window::SetupWindow(unsigned int width, unsigned int height, std::string title, bool vSync, bool fullscreen)
{
	// Initialises the window and enables or disables vSync based on parameter and the same for Fullscreen
	fullscreen ? m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Fullscreen) : m_Window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Default);
	m_Window->setVerticalSyncEnabled(vSync);
		
	// Calls the InitialiseGame function to add all scenes to the game
	InitialiseGameLayer();
}

void AutumnEngine::Window::InitialiseGameLayer()
{
	// Creates a new Game Layer passing in the current Window
	m_GameLayer = AutumnEngine::GameLayer(m_Window);

	// Calls the Game Layers initialise function to initialise the Game Layer
	m_GameLayer.InitialiseGame();
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
				m_GameLayer.GetInput()->SetKeyDown(m_Event.key.code);
			}
				break;
			case sf::Event::KeyReleased:
			{
				// Set the key pressed to up
				m_GameLayer.GetInput()->SetKeyUp(m_Event.key.code);
			}
				break;
			case sf::Event::MouseMoved:
			{
				// Sets the mouses position to the current position
				m_GameLayer.GetInput()->SetMousePosition(m_Event.mouseMove.x, m_Event.mouseMove.y);
			}
				break;
			case sf::Event::MouseButtonPressed:
			{
				// Sets the left mouse left button to down
				if (m_Event.key.code == sf::Mouse::Left)
					m_GameLayer.GetInput()->SetLeftMouse(AutumnEngine::Input::MouseState::DOWN);

				// Sets the right mouse left button to down
				if (m_Event.key.code == sf::Mouse::Right)
					m_GameLayer.GetInput()->SetRightMouse(AutumnEngine::Input::MouseState::DOWN);
			}
				break;
			case sf::Event::MouseButtonReleased:
			{
				// Sets the left mouse left button to up
				if (m_Event.key.code == sf::Mouse::Left)
					m_GameLayer.GetInput()->SetLeftMouse(AutumnEngine::Input::MouseState::UP);

				// Sets the left mouse left button to up
				if (m_Event.key.code == sf::Mouse::Right)
					m_GameLayer.GetInput()->SetRightMouse(AutumnEngine::Input::MouseState::UP);
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

		// Calculate Delta Time and Update the running Game Layer passing in the current Delta Time
		m_DeltaTime = m_Clock.restart().asSeconds();
		m_GameLayer.Update(m_DeltaTime);
	}
}