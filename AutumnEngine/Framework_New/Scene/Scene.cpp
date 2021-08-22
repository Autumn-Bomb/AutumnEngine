#include "Scene.h"

AutumnEngine::Scene::Scene() {}
AutumnEngine::Scene::~Scene() {}

void AutumnEngine::Scene::AddEntityToScene(AutumnEngine::Entity& entity)
{

}

void AutumnEngine::Scene::RemoveEntityFromScene(AutumnEngine::Entity& entity)
{

}

void AutumnEngine::Scene::BatchScene()
{
	for (auto& entity : m_Entities)
	{
		// LOOP THROUGH ALL ENTITIES WITH SPRITE RENDERER AND DRAW
	}
}

void AutumnEngine::Scene::DrawScene()
{
	m_SceneTexture.display();
}