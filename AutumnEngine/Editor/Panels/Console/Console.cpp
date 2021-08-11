#include "Console.h"

AutumnEngine::Console::Console()
{
    m_AutoScroll = true;
    Clear();

    AddMessage(MessageType::MESSAGE, "This is a normal message\n");
    AddMessage(MessageType::WARNING, "This is a warning message\n");
    AddMessage(MessageType::ERROR, "This is an error message\n");
}
AutumnEngine::Console::~Console(){}

void AutumnEngine::Console::AddMessage(MessageType messageType, const char* message, ...)
{
    std::string newMessage;
    switch (messageType)
    {
        case MessageType::MESSAGE:
        {
            newMessage = "[MESSAGE] " + std::string(message);
        }
            break;
        case MessageType::WARNING:
        {
            newMessage = "[WARNING] " + std::string(message);
        }
            break;
        case MessageType::ERROR:
        {
            newMessage = "[ERROR] " + std::string(message);
        }
            break;
    }

    const char* finalMessage = newMessage.c_str();

    int oldSize = m_Buffer.size();
    va_list args;
    va_start(args, finalMessage);
    m_Buffer.appendfv(finalMessage, args);
    va_end(args);

    for (int newSize = m_Buffer.size(); oldSize < newSize; oldSize++)
    {
        if (m_Buffer[oldSize] == '\n')
        {
            m_LineOffsets.push_back(oldSize + 1);
        }
    }
}

void AutumnEngine::Console::ShowConsole()
{
      ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 255));
      ImGui::Begin("Console");

      if (ImGui::MenuItem("Clear")) { Clear(); }

      ImGui::Separator();
      ImGui::BeginChild("Scrollbar", ImVec2(0, 0), false, ImGuiWindowFlags_AlwaysVerticalScrollbar);

      ImGuiListClipper clipper;
      clipper.Begin(m_LineOffsets.Size);

      while (clipper.Step())
      {
          for (int lineNo = clipper.DisplayStart; lineNo < clipper.DisplayEnd; lineNo++)
          {
              const char* lineStart = m_Buffer.begin() + m_LineOffsets[lineNo];
              const char* lineEnd = (lineNo + 1 < m_LineOffsets.Size) ? (m_Buffer.begin() + m_LineOffsets[lineNo + 1] - 1) : m_Buffer.end();
              ImGui::TextUnformatted(lineStart, lineEnd);
          }
      }
      clipper.End();

      ImGui::PopStyleColor();

      if (m_AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
          ImGui::SetScrollHereY(1.0f);

      ImGui::EndChild();
      ImGui::End();
}