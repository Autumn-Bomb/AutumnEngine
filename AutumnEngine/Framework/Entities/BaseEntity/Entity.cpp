#include "Entity.h"

AutumnEngine::Entity::Entity()
{
	m_ID = 0;
	m_Name = "";
	m_Tag = "";
	m_Layer = 0;

	m_IsActive = true;
}
AutumnEngine::Entity::~Entity() {}