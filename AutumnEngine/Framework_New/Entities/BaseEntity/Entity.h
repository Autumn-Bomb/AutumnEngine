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