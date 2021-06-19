#include "Input.h"

AutumnEngine::Input::Input()
{
	m_Mouse.left = MouseState::UP;
	m_Mouse.right = MouseState::UP;
	m_Mouse.x = 0;
	m_Mouse.y = 0;
}

void AutumnEngine::Input::SetKeyDown(int key)
{
	if (key >= 0)
	{
		m_Keys[key] = true;
	}
}

void AutumnEngine::Input::SetKeyUp(int key)
{
	if (key >= 0)
	{
		m_Keys[key] = false;
	}
}

bool AutumnEngine::Input::IsKeyDown(int key)
{
	if (key >= 0)
	{
		return m_Keys[key];
	}
	return false;
}

bool AutumnEngine::Input::IsPressed(int key)
{
	bool cond = IsKeyDown(key);
	if (cond)
	{
		m_Pressed.push_back(key);
		return cond;
	}
	return false;
}

void AutumnEngine::Input::Update()
{
	for (int i = 0; i < m_Pressed.size(); i++)
	{
		SetKeyUp(m_Pressed[i]);
	}
	m_Pressed.clear();

	if (m_Mouse.left == MouseState::PRESSED)
	{
		m_Mouse.left = MouseState::UP;
	}

	if (m_Mouse.right == MouseState::PRESSED)
	{
		m_Mouse.right = MouseState::UP;
	}
}

void AutumnEngine::Input::SetMouseX(int lx)
{
	m_Mouse.x = lx;
}

void AutumnEngine::Input::SetMouseY(int ly)
{
	m_Mouse.y = ly;
}

void AutumnEngine::Input::SetMousePosition(int lx, int ly)
{
	SetMouseX(lx);
	SetMouseY(ly);
}

int AutumnEngine::Input::GetMouseX()
{
	return m_Mouse.x;
}

int AutumnEngine::Input::GetMouseY()
{
	return m_Mouse.y;
}

void AutumnEngine::Input::SetLeftMouse(MouseState state)
{
	m_Mouse.left = state;
}

bool AutumnEngine::Input::IsLeftMouseDown()
{
	if (m_Mouse.left == MouseState::DOWN || m_Mouse.left == MouseState::PRESSED)
	{
		return true;
	}
	return false;
}

bool AutumnEngine::Input::IsLeftMousePressed()
{
	if (m_Mouse.left == MouseState::DOWN || m_Mouse.left == MouseState::PRESSED)
	{
		m_Mouse.left = MouseState::PRESSED;
		return true;
	}
	return false;
}

void AutumnEngine::Input::SetRightMouse(MouseState state)
{
	m_Mouse.right = state;
}

bool AutumnEngine::Input::IsRightMouseDown()
{
	if (m_Mouse.right == MouseState::DOWN || m_Mouse.right == MouseState::PRESSED)
	{
		return true;
	}
	return false;
}

bool AutumnEngine::Input::IsRightMousePressed()
{
	if (m_Mouse.right == MouseState::DOWN || m_Mouse.right == MouseState::PRESSED)
	{
		m_Mouse.right = MouseState::PRESSED;
		return true;
	}
	return false;
}