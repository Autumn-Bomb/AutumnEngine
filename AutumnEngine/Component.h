#pragma once
#include "SFML/Graphics.hpp"

namespace AutumnEngine
{
	class Component
	{
		struct Transform
		{
			const sf::Vector2f m_Size;

			sf::Vector2f m_Position;
			sf::Vector2f m_Rotation;
		};

		struct SpriteRenderer
		{
			const bool m_IsRendered;
			const int m_Layer;

			const sf::Texture* m_Texture;
			const sf::Color m_Colour;
		};

		struct BoxCollider
		{
			const bool m_IsCollider;

			const sf::Vector2f m_Position;
			const sf::IntRect m_CollisionBox;
		};

		struct Rigidbody
		{
			const bool m_IsKinematic;
			const float m_Gravity = 9.8f;

			sf::Vector2f m_Velocity;
		};
	};
}