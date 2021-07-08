#pragma once
#include "../../Framework/Entity/Entity.h"

namespace AutumnEngine
{
	class ImBatman : public Entity
	{
		public:
			ImBatman();
			ImBatman(sf::Texture* spriteTexture, std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer);
			~ImBatman();

			void Move(int x, int y);
			void Render(sf::RenderWindow* window);
	};
}