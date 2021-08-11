#pragma once
#include "../imgui/imgui.h"
#include <iostream>

namespace AutumnEngine
{
	enum MessageType { MESSAGE, WARNING, ERROR };

	class Console
	{
		// CONSTRUCTOR AND DESTRUCTOR
		public:
			Console();
			~Console();

		// METHODS TO CALL TO SHOW AND HIDE CONSOLE
		public:
			void ShowConsole();
			void AddMessage(MessageType messageType, const char* message, ...);

			void Clear() { m_Buffer.clear(); m_LineOffsets.clear(); m_LineOffsets.push_back(0); }

		// Getters and Setters
		public:
			void SetShow(bool show) { m_Show = show; }

		// Console Variables
		private:
			MessageType m_MessageType;
			ImVector<int> m_LineOffsets;
			bool m_Show;
			bool m_AutoScroll;
			ImGuiTextBuffer m_Buffer;
	};
}