#pragma once
#include "imgui.h"

namespace AutumnEngine
{
	class Profiler
	{
		public:
			Profiler();
			~Profiler();

		public:
			void ShowStats(unsigned int& fps, float& frameTime);
	};
}