#pragma once
#include <vector>
#include "Entity.h"

namespace AutumnEngine
{
	class BubbleSort
	{
		public:
			BubbleSort();

			static void SortSpriteLayers(std::vector<Entity>& sprites, int size)
			{
				bool swapped;

				for (int i = 0; i < (size - 1); i++)
				{
					swapped = false;

					for (int j = 0; (j < size - i - 1); j++)
					{
						if (sprites[j].GetSprite().GetLayer() > sprites[j + 1].GetSprite().GetLayer())
						{						
							Sprite temp = sprites[j].GetSprite();
							sprites[j] = sprites[j + 1];
							sprites[j + 1].GetSprite() = temp;

							swapped = true;
						}
					}

					if (!swapped)
						break;
				}
			}
	};
}