#pragma once

#include "imgui.h"
#include "imgui-SFML.h"

namespace AutumnEngine
{
	class Style
	{
		public:
			Style() { m_Font = nullptr; m_Style = nullptr; m_FontSize = 14.0f; }
			Style(ImGuiStyle& style)
			{ 
				m_Style = &style; 
				m_FontSize = 14.0f;

				ImGui::GetIO().Fonts->Clear();
				m_Font = ImGui::GetIO().Fonts->AddFontFromFileTTF(m_FontPath.c_str(), m_FontSize);
				ImGui::SFML::UpdateFontTexture();

				SetStyle();
			}
			~Style() {}

		public:
			void SetStyle()
			{
				m_Style->WindowRounding = 5.3f;
				m_Style->FrameRounding = 2.3f;
				m_Style->ScrollbarRounding = 0;

				m_Style->Colors[ImGuiCol_Text] = ImVec4(1.f, 1.f, 1.f, 1.00f);
				m_Style->Colors[ImGuiCol_TextDisabled] = ImVec4(1, 1, 0.60f, 1.00f);
				m_Style->Colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.15f, 1.00f);
				m_Style->Colors[ImGuiCol_ChildBg] = ImVec4(230, 64, 32, 0.0f);
				m_Style->Colors[ImGuiCol_PopupBg] = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
				m_Style->Colors[ImGuiCol_Border] = ImVec4(0.70f, 0.70f, 0.70f, 0.65f);
				m_Style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
				m_Style->Colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.01f, 1.00f);
				m_Style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.90f, 0.80f, 0.80f, 0.40f);
				m_Style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.90f, 0.65f, 0.65f, 0.45f);
				m_Style->Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.83f);
				m_Style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.40f, 0.40f, 0.80f, 0.20f);
				m_Style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 0.00f, 0.00f, 0.87f);
				m_Style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
				m_Style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
				m_Style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.55f, 0.53f, 0.55f, 0.51f);
				m_Style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.56f, 1.00f);
				m_Style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.91f);
				m_Style->Colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.83f);
				m_Style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.70f, 0.70f, 0.62f);
				m_Style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.30f, 0.30f, 0.84f);
				m_Style->Colors[ImGuiCol_Button] = ImVec4(0.48f, 0.72f, 0.89f, 0.49f);
				m_Style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);
				m_Style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
				m_Style->Colors[ImGuiCol_Header] = ImVec4(0.30f, 0.69f, 1.00f, 0.53f);
				m_Style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.44f, 0.61f, 0.86f, 1.00f);
				m_Style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.38f, 0.62f, 0.83f, 1.00f);
				m_Style->Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
				m_Style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
				m_Style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
				m_Style->Colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
				m_Style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
				m_Style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
				m_Style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
				m_Style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
				
				m_Style->WindowMenuButtonPosition = ImGuiDir_None;
				m_Style->WindowRounding = 0.f;
			}

		public:
			void SetTextColour(ImVec4 newColour) { m_Style->Colors[ImGuiCol_Text] = ImVec4(newColour.x, newColour.y, newColour.z, 1); }
			void SetBackgroundColour(ImVec4 newColour) { m_Style->Colors[ImGuiCol_WindowBg] = ImVec4(newColour.x, newColour.y, newColour.z, 1); }
			
			void SetFont(std::string path)
			{
				ImGui::GetIO().Fonts->Locked = false;
				m_Font = ImGui::GetIO().Fonts->AddFontFromFileTTF(m_FontPath.c_str(), m_FontSize);
				ImGui::SFML::UpdateFontTexture();
			}

		public:
			ImColor GetBackgroundColour() { return m_Style->Colors[ImGuiCol_WindowBg]; }
			ImColor GetTextColour() { return m_Style->Colors[ImGuiCol_Text]; }
			std::string GetFontPath() { return m_FontPath; }
			
		private:
			std::string m_FontPath = "Editor/Style/Font/font.ttf";
			float m_FontSize;

		private:
			ImFont* m_Font;
			ImGuiStyle* m_Style;
	};
}