#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace AutumnEngine
{
	class Collision
	{
		public:
			static bool CheckBoundingBox(sf::RectangleShape* object1, sf::RectangleShape* object2);
			static bool CheckBoundingBox(sf::RectangleShape* object1, sf::Vector2i mouse);
			static bool CheckBoundingBoxCircle(sf::CircleShape* object1, sf::RectangleShape* object2);
	};
}