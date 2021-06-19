#pragma once
#include <vector>

namespace AutumnEngine
{
	class Input
	{
		public:
			enum class MouseState { UP, DOWN, PRESSED };

			Input();
			// Functions for setting key as pressed, released and checking current state.
			void SetKeyDown(int key);
			void SetKeyUp(int key);
			bool IsKeyDown(int key);
			bool IsPressed(int key);
			void Update();

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

		private:
			
			struct Mouse
			{
				int x, y;
				MouseState left, right;
			};
			
			bool m_Keys[256]{ false };
			std::vector<int> m_Pressed;
			Mouse m_Mouse;
	};
}