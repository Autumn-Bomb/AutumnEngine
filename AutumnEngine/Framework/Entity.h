#pragma once
#include <iostream>
#include <random>

#include "Component.h"

namespace AutumnEngine
{
	class Entity
	{
		public:
			Entity();
			~Entity();

			template <typename Component>
			void AddComponent(Component component);

			template <typename Component>
			void RemoveComponent(Component component);

			void ListAttachedComponents();

		private:
			unsigned long entityID;
			std::vector<AutumnEngine::Component> components;
	};
}