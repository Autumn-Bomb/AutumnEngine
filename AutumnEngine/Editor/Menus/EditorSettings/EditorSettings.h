#pragma once
#include "../../Json/json.hpp"
#include "../../Style/Style.h"
#include "../../Panels/ContentBrowser/ContentBrowser.h"

#include "../../Panels/BasePanel/BasePanel.h"

namespace AutumnEngine
{
	class EditorSettings : public AutumnEngine::Panel
	{
		public:
			EditorSettings();
			~EditorSettings();

		public:
			void OnImGuiRender() override;
			void ApplyChanges();

			void ApplyLastStyle();

		public:
			void SaveEditorSettings();

		public:
			void RenderContentBrowserSettings();
			void RenderOverallStyleSettings();

		public:
			void SetContentBroswer(AutumnEngine::ContentBrowser* contentBrowser) { m_ContentBrowser = contentBrowser; }
			void SetStyle(AutumnEngine::Style* style)
			{ 
				m_CurrentStyle = AutumnEngine::Style(*style);
			}

		private:
			float m_TextColour[4]{ 1.f, 1.f, 1.f, 1.f };
			float m_BackgroundColour[4]{ 0.09f, 0.09f, 0.15f, 1.00f };

		private:
			std::ifstream m_SettingsFile;
			std::string m_EditorSettingsPath = "Editor/Resources/EditorSettings/settings.resource";
			nlohmann::json m_EditorSettingsFile;
			AutumnEngine::Style m_CurrentStyle;
			AutumnEngine::ContentBrowser* m_ContentBrowser;
	};
}