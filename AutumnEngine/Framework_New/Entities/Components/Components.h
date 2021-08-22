#pragma once
#include "../../../Framework/GUI/Sprite/Sprite.h"

namespace AutumnEngine
{
	class Components
	{
		public:
			struct Transform
			{
				float m_X;
				float m_Y;
				float m_Z;
			
				float m_RotX;
				float m_RotY;
				float m_RotZ;

				float m_ScaleX;
				float m_ScaleY;
				float m_ScaleZ;
			};

			struct SpriteRenderer2D
			{
				AutumnEngine::Sprite m_Sprite;
				sf::Color m_Colour;
				int m_Layer;
			};

			struct BoxCollider2D
			{
				int m_Width;
				int m_Height;

				bool m_IsTrigger;
			};

			struct CircleCollider2D
			{
				float m_Radius;

				bool m_IsTrigger;
			};

			struct RigidBody2D
			{
				float m_Mass;
				float m_Drag;

				bool m_UseGravity;
				bool m_IsKinematic;
			};
	};
}