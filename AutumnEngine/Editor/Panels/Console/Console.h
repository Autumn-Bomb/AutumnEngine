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

		// CONSOLE VARIABLES
		private:
			const char* m_FilterText[5] = { "NONE", "MESSAGE", "ACTION", "WARNING", "ERROR"};
			const char* m_CurrentItem = "No Filter";
			bool m_AutoScroll;

			MessageType m_MessageType;
			ImVector<int> m_LineOffsets;
			ImGuiTextBuffer m_Buffer;
			ImGuiTextFilter m_Filter;
	};
}