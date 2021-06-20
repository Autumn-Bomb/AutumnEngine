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

			void AddComponent(AutumnEngine::Component component);
			void RemoveComponent(AutumnEngine::Component component);

			void ListAttachedComponents();

		private:
			unsigned long entityID;
			std::vector<AutumnEngine::Component> components;
	};
}