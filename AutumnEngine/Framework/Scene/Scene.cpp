#include "Scene.h"

AutumnEngine::Scene::Scene() {}
AutumnEngine::Scene::~Scene() {}

void AutumnEngine::Scene::OnSceneOpened(AutumnEngine::Hierarchy& SceneHierarchy)
{
	// Loop through all entities in the scene file, creating Tree nodes for each one
}

void AutumnEngine::Scene::OnCreate() {}
void AutumnEngine::Scene::OnDestroy() {}
void AutumnEngine::Scene::OnActivate() {}
void AutumnEngine::Scene::OnDeactivate() {}

void AutumnEngine::Scene::DrawScene()
{
	// Get access to each system in the scene, render all SpriteRenderer Components
}

void AutumnEngine::Scene::OnSceneClosed()
{
	// Save the current scenes Entities and their components in the scene file

}