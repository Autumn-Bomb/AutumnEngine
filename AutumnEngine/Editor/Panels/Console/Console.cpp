#include "Console.h"

AutumnEngine::Console::Console()
{
    m_AutoScroll = true;
    Clear();

    m_CurrentItem = m_FilterText[0];
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
        case MessageType::ACTION:
        {
            newMessage = "[ACTION] " + std::string(message);
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

void AutumnEngine::Console::OnImGuiRender()
{
      ImGui::Begin("Console", &GetActiveState());

      if (ImGui::Button("Clear")) { Clear(); }

      ImGui::SameLine(ImGui::GetWindowWidth() - 100);
      ImGui::Checkbox("Auto Scroll", &m_AutoScroll);
      ImGui::SameLine(ImGui::GetWindowWidth() - 210);
      
      ImGui::PushItemWidth(100);
      if (ImGui::BeginCombo("##Filter", m_CurrentItem))
      {
          for (int filter = 0; filter < IM_ARRAYSIZE(m_FilterText); filter++)
          {
              bool isSelected = (m_CurrentItem == m_FilterText[filter]);

              if (ImGui::Selectable(m_FilterText[filter], isSelected))
                  m_CurrentItem = m_FilterText[filter];

              if (isSelected)
                  ImGui::SetItemDefaultFocus();
          }
          ImGui::EndCombo();
      }
      ImGui::PopItemWidth();

      ImGui::Separator();

      if(!m_AutoScroll)
        ImGui::BeginChild("ScrollbarVertical", ImVec2(0, 0), false, ImGuiWindowFlags_AlwaysVerticalScrollbar);

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

      if (m_AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
          ImGui::SetScrollHereY(1.0f);
      
      if(!m_AutoScroll)
        ImGui::EndChild();

      ImGui::End();
}