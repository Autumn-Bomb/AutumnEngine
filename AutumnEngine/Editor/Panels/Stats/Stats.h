#pragma once
#include "imgui.h"

namespace AutumnEngine
{
	class Stats
	{
		public:
			Stats();
			~Stats();

		public:
			void ShowStats(unsigned int& fps, float& frameTime);
	};
}