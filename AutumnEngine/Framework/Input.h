#pragma once
#include <vector>

namespace AutumnEngine
{
	class Input
	{
		// ENUM TO CONTROL THE CURRENT STATE OF A MOUSE BUTTON
		public:
			enum class MouseState { UP, DOWN, PRESSED };

		// CONSTRUCTOR
		public:
			Input();

		// METHOD DEFINITIONS
		public:
			void Update();
		
		// GETTERS AND SETTERS
		public:
			// Functions for setting key as pressed, released and checking current state.
			void SetKeyDown(int key);
			void SetKeyUp(int key);
			bool IsKeyDown(int key);
			bool IsPressed(int key);

			// Functions are mouse input, including getting and setting current position and mouse button presses.
			void SetMouseX(int lx);
			void SetMouseY(int ly);
			void SetMousePosition(int lx, int ly);
			int GetMouseX();
			int GetMouseY();
			void SetLeftMouse(MouseState state);
			bool IsLeftMouseDown();
			bool IsLeftMousePressed();
			void SetRightMouse(MouseState state);
			bool IsRightMouseDown();
			bool IsRightMousePressed();

		// MOUSE OBJECT CREATION
		private:
			struct Mouse
			{
				int x, y;
				MouseState left, right;
			};
			Mouse m_Mouse;

		// CONTAINERS FOR KEYS PRESSED AND RELEASED
		private:
			bool m_Keys[256]{ false };
			std::vector<int> m_Pressed;
	};
}