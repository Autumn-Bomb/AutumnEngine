#pragma once
#include "imgui.h"
#include "../../Style/Style.h"
#include "../../Panels/ContentBrowser/ContentBrowser.h"

namespace AutumnEngine
{
	class EditorSettings
	{
		public:
			EditorSettings();
			~EditorSettings();

		public:
			void OnImGuiRender(bool& open);
			void ApplyChanges();

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
			AutumnEngine::Style m_CurrentStyle;
			AutumnEngine::ContentBrowser* m_ContentBrowser;
	};
}