#pragma once
#include <vector>
#include "UIComponent.h"

namespace AutumnEngine
{
	class BubbleSort
	{
	public:
		BubbleSort() {}

		static void SortComponentLayers(std::vector<UIComponent>& uiComponent, int size)
		{
			bool swapped;

			for (int i = 0; i < (size - 1); i++)
			{
				swapped = false;

				for (int j = 0; (j < size - i - 1); j++)
				{
					if (uiComponent[j].GetRenderingLayer() > uiComponent[j + 1].GetRenderingLayer())
					{
						UIComponent temp = uiComponent[j].GetCurrentUIComponent();
					    uiComponent[j] = uiComponent[j + 1];
						uiComponent[j + 1].GetCurrentUIComponent() = temp;

						swapped = true;
					}
				}

				if (!swapped)
					break;
			}
		}
	};
}