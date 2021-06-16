#pragma once
#include "SFML/Graphics.hpp"

namespace AutumnEngine
{
	class Component
	{
		public:
			struct Transform
			{
				sf::Vector2f m_Size;
				sf::Vector2f m_Position;
				sf::Vector2f m_Rotation;
			};

			struct SpriteRenderer2D
			{
				bool m_IsRendered;
				int m_Layer;

				sf::Texture* m_Texture;
				sf::Color m_Colour;
			};

			struct BoxCollider2D
			{
				bool m_IsCollider;

				sf::Vector2f m_Position;
				sf::IntRect m_CollisionBox;
			};

			struct Rigidbody2D
			{
				bool m_IsKinematic;
				float m_Gravity = 9.8f;

				sf::Vector2f m_Velocity;
			};
	};
}