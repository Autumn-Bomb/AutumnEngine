#pragma once
#include "../Components/Components.h"
#include "entt.hpp"

namespace AutumnEngine
{
	class Entity
	{
		// CONSTRUCTOR AND DESTRUCTOR
		public:
			Entity();
			~Entity();

		// FUNCTIONS USED BY THE ENTITY CLASS
		public:
			template <typename T>
			void AddComponent(T component);

			template <typename T>
			void RemoveComponent(T component);

		public:
			template <typename T>
			bool HasComponent(T component)
			{
				if (component != nullptr)
					return true;
				else
					return false;
			}

		// VARIABLES USED BY THE ENTITY CLASS
		private:
			uint16_t m_ID;
			std::string m_Name;
			std::string m_Tag;

			int m_Layer;
			bool m_IsActive;
	};
}