#include "Collision.h"

bool AutumnEngine::Collision::CheckBoundingBox(sf::RectangleShape* object1, sf::RectangleShape* object2)
{
	if (object1->getGlobalBounds().left + object1->getGlobalBounds().width < object2->getGlobalBounds().left)
		return false;
	if (object1->getGlobalBounds().left > object2->getGlobalBounds().left + object2->getGlobalBounds().width)
		return false;
	if (object1->getGlobalBounds().top + object1->getGlobalBounds().height < object2->getGlobalBounds().top)
		return false;
	if (object1->getGlobalBounds().top > object2->getGlobalBounds().top + object2->getGlobalBounds().height)
		return false;

	return true;
}

bool AutumnEngine::Collision::CheckBoundingBox(sf::RectangleShape* object1, sf::Vector2i mouse)
{
	if (object1->getGlobalBounds().left + object1->getGlobalBounds().width < mouse.x)
		return false;
	if (object1->getGlobalBounds().left > mouse.x)
		return false;
	if (object1->getGlobalBounds().top + object1->getGlobalBounds().height < mouse.y)
		return false;
	if (object1->getGlobalBounds().top > mouse.y)
		return false;

	return true;
}

bool AutumnEngine::Collision::CheckBoundingBoxCircle(sf::CircleShape* object1, sf::RectangleShape* object2)
{
	if (object1->getGlobalBounds().left + object1->getGlobalBounds().width < object2->getGlobalBounds().left)
		return false;
	if (object1->getGlobalBounds().left > object2->getGlobalBounds().left + object2->getGlobalBounds().width)
		return false;
	if (object1->getGlobalBounds().top + object1->getGlobalBounds().height < object2->getGlobalBounds().top)
		return false;
	if (object1->getGlobalBounds().top > object2->getGlobalBounds().top + object2->getGlobalBounds().height)
		return false;

	return true;
}