#include "../Framework/Entity.h"

AutumnEngine::Entity::Entity()
{
	entityID = rand() % 100000 + 16;
	std::cout << "Entity ID: " << std::to_string(entityID) << std::endl;
}
AutumnEngine::Entity::~Entity() {}

void AutumnEngine::Entity::AddComponent(AutumnEngine::Component component)
{
	components.push_back(component);
}

void AutumnEngine::Entity::RemoveComponent(AutumnEngine::Component component)
{
	//components.erase(component);
}

void AutumnEngine::Entity::ListAttachedComponents()
{
	for (AutumnEngine::Component attachedComponent : components)
	{
		
	}
}