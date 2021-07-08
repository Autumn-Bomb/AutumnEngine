#pragma once
#include "../GUI/Sprite/Sprite.h"

namespace AutumnEngine
{
	class Entity
	{
		// CONSTRUCTORS AND DESTRUCTORS
		public:
			Entity();
			Entity(sf::Texture* spriteTexture, std::string name, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer);
			~Entity();

		// FUNCTION DEFINITIONS
		public:
			void Move(int x, int y);
			void Draw(sf::RenderWindow* window);

		// GETTERS AND SETTERS
		public:
			void SetMovementSpeed(float movementSpeed) { m_MovementSpeed = movementSpeed; }
			sf::Vector2f GetPosition() { return m_Position; }

			void SetAlive(bool isAlive) { m_IsAlive = isAlive; }
			bool GetIsAlive() { return m_IsAlive; }

			void SetEntityName(std::string entityName) { m_EntityName = entityName; }
			std::string GetEntityName() { return m_EntityName; }

		// VARIABLES THAT DON'T NEED TO BE EXPOSED
		private:	
			std::string m_EntityName;
			float m_MovementSpeed;
			bool m_IsAlive;
			sf::Vector2f m_Position;

		// VARIABLES WE WANT EACH ENTITY TO HAVE ACCESS TO
		protected:
			AutumnEngine::Sprite* m_Sprite;
	};
}