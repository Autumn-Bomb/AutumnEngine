#pragma once
#include "../../../Framework/Entities/BaseEntity/Entity.h"
#include "imgui.h"

namespace AutumnEngine
{
	class Inspector
	{
		public:
			Inspector();
			~Inspector();

		public:
			void ShowInspector();

		private:
			AutumnEngine::Entity* m_Entity;
	};
}