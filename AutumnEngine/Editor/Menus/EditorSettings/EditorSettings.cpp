#include "EditorSettings.h"

AutumnEngine::EditorSettings::EditorSettings()
{
	m_SettingsFile = std::ifstream("Editor/Resources/EditorSettings/settings.resource");
	m_SettingsFile >> m_EditorSettingsFile;
}
AutumnEngine::EditorSettings::~EditorSettings() {}

void AutumnEngine::EditorSettings::ApplyLastStyle()
{
	for (int line = 0; line < m_EditorSettingsFile["Theme"].size(); line++)
	{
		m_CurrentStyle.SetBackgroundColour(ImVec4(m_EditorSettingsFile["Theme"][line]["BGR_R"], m_EditorSettingsFile["Theme"][line]["BGR_G"], m_EditorSettingsFile["Theme"][line]["BGR_B"], m_EditorSettingsFile["Theme"][line]["BGR_A"]));
		m_CurrentStyle.SetTextColour(ImVec4(m_EditorSettingsFile["Theme"][line]["TXT_R"], m_EditorSettingsFile["Theme"][line]["TXT_G"], m_EditorSettingsFile["Theme"][line]["TXT_B"], m_EditorSettingsFile["Theme"][line]["TXT_A"]));
	}
}

void AutumnEngine::EditorSettings::OnImGuiRender(bool& open)
{
	ImGui::Begin("Editor Settings", &open, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDocking);
	ImGui::SetWindowSize(ImVec2(700, 500));
	ImGui::Text("Use this menu to change the avaliable Editor Settings");
	ImGui::Separator();

	// RENDER SETTINGS MENUS FOR EACH PANEL
	RenderContentBrowserSettings();
	RenderOverallStyleSettings();

	if (ImGui::Button("Apply", ImVec2(50, 30))) { ApplyChanges(); }

	ImGui::End();
}

void AutumnEngine::EditorSettings::RenderContentBrowserSettings()
{
	// CONTENT BROSWER SETTINGS
	ImGui::Text("Content Browser - ");
	ImGui::PushItemWidth(150.f);
	ImGui::Text("Thumbnail Size:");
	ImGui::SameLine(ImGui::GetWindowWidth() - 475);
	ImGui::SliderFloat("##Thumbnail Size", m_ContentBrowser->GetThumbnailSize(), 50, 100);
	ImGui::Text("Thumbnail Padding:");
	ImGui::SameLine(ImGui::GetWindowWidth() - 475);
	ImGui::SliderFloat("##Thumbnail Padding", m_ContentBrowser->GetThumbnailPadding(), 10, 20);
	ImGui::Text("Compact List:");
	ImGui::SameLine(ImGui::GetWindowWidth() - 475);
	ImGui::Checkbox("##CompactList", m_ContentBrowser->GetIsCompact());
	ImGui::Separator();
}

void AutumnEngine::EditorSettings::RenderOverallStyleSettings()
{
	ImGui::Text("Engine Settings - ");
	ImGui::Text("Font Path:");
	ImGui::SameLine(ImGui::GetWindowWidth() - 475);
	ImGui::PushItemWidth(200);
	ImGui::InputText("##FontPath", (char*)m_CurrentStyle.GetFontPath().c_str(), 128);
	ImGui::PopItemWidth();
	ImGui::Text("Editor Theme:");
	ImGui::Text("Text Colour:");
	ImGui::SameLine(ImGui::GetWindowWidth() - 475);
	ImGui::ColorEdit3("##Text", m_TextColour);
	ImGui::Text("Background Colour:");
	ImGui::SameLine(ImGui::GetWindowWidth() - 475);
	ImGui::ColorEdit3("##Background", m_BackgroundColour);

	ImGui::Separator();
}

void AutumnEngine::EditorSettings::ApplyChanges()
{
	m_CurrentStyle.SetTextColour(ImVec4(m_TextColour[0], m_TextColour[1], m_TextColour[2], m_TextColour[3]));
	m_CurrentStyle.SetBackgroundColour(ImVec4(m_BackgroundColour[0], m_BackgroundColour[1], m_BackgroundColour[2], m_BackgroundColour[3]));
	m_CurrentStyle.SetFont(m_CurrentStyle.GetFontPath().c_str());

	//SaveEditorSettings();
}

void AutumnEngine::EditorSettings::SaveEditorSettings()
{
	std::ofstream stream(m_EditorSettingsPath);

	m_EditorSettingsFile =
	{
	   "Theme",
	   {
			"BRG", m_EditorSettingsFile["BGR"] = { m_BackgroundColour[0] * 255, m_BackgroundColour[1] * 255, m_BackgroundColour[2] * 255, m_BackgroundColour[3] * 255} ,
			"TXT", m_EditorSettingsFile["TXT"] = { m_TextColour[0] * 255, m_TextColour[1] * 255, m_TextColour[2] * 255, m_TextColour[3] * 255}
	   }
	};

	stream << std::setw(4) << m_EditorSettingsFile;
}