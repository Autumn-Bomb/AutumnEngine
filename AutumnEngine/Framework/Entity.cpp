#include "../Framework/Entity.h"

AutumnEngine::Entity::Entity()
{
	entityID = rand() % 100000 + 16;

	std::cout << "Entity ID: " << std::to_string(entityID) << std::endl;
}
AutumnEngine::Entity::~Entity() {}

template <typename  Component>
void AutumnEngine::Entity::AddComponent(Component component)
{
	components.push_back(component);
}

template <typename Component>
void AutumnEngine::Entity::RemoveComponent(Component component)
{
	components.erase(component);
}

void AutumnEngine::Entity::ListAttachedComponents()
{
	for (AutumnEngine::Component attachedComponent : components)
	{
		
	}
}