#pragma once
#include "imgui.h"
#include "imgui-SFML.h"

namespace AutumnEngine
{
	class Panel
	{
		public:
			Panel() { ShowPanel(true); }
			~Panel() {}

		public:
			virtual void OnImGuiRender() {};

		public:
			void ShowPanel(bool show) { m_Show = show; }

		public:
			bool& GetActiveState() { return m_Show; }

		protected:
			bool m_Show;
	};
}