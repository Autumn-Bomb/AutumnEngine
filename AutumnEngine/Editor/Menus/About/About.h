#pragma once

#include "../../../Editor/Panels/BasePanel/BasePanel.h"

namespace AutumnEngine
{
	class About : public AutumnEngine::Panel
	{
		public:
			About();
			~About();

		public:
			void OnImGuiRender() override;
	};
}