#include "BaseScene.h"

AutumnEngine::BaseScene::BaseScene(){}
AutumnEngine::BaseScene::~BaseScene(){}

void AutumnEngine::BaseScene::Begin()
{
	m_Window->clear(sf::Color::Black);
}
void AutumnEngine::BaseScene::Begin(sf::Color color)
{
	m_Window->clear(color);
}

void AutumnEngine::BaseScene::Awake() {}
void AutumnEngine::BaseScene::HandleInput(float dt){}
void AutumnEngine::BaseScene::Update(float dt){}
void AutumnEngine::BaseScene::LoadAssets(){}
void AutumnEngine::BaseScene::UnloadAssets(){}
void AutumnEngine::BaseScene::Render(){}

void AutumnEngine::BaseScene::End()
{
	m_Window->display();
}