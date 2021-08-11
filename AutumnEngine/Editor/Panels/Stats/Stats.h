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
			void ShowStats(int& fps, float& frameTime);
	};
}