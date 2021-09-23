#pragma once
#include "../BasePanel/BasePanel.h"

namespace AutumnEngine
{
	class Animation : public AutumnEngine::Panel
	{
		public:
			Animation();
			~Animation();

		public:
			void OnImGuiRender() override;
	};
}