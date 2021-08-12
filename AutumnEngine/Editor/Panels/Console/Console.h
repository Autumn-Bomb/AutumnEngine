#pragma once
#include "imgui.h"
#include <string>

namespace AutumnEngine
{
	enum MessageType { MESSAGE, WARNING, ERROR, ACTION };

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

		// Console Variables
		private:
			MessageType m_MessageType;
			ImVector<int> m_LineOffsets;
			bool m_AutoScroll;
			ImGuiTextBuffer m_Buffer;
	};
}