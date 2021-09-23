#pragma once
#include "../../../Framework/Entities/BaseEntity/Entity.h"
#include "../BasePanel/BasePanel.h"

namespace AutumnEngine
{
	class Inspector : public AutumnEngine::Panel
	{
		public:
			Inspector();
			~Inspector();

		public:
			void OnImGuiRender() override;

		private:
			AutumnEngine::Entity* m_Entity;
	};
}