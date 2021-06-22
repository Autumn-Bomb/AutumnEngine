#include "TestScene.h"

AutumnEngine::TestScene::TestScene() {}
AutumnEngine::TestScene::TestScene(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiLayer)
{
	SetRenderWindow(&window);
	SetGUILayer(&guiLayer);
	SetInput(&input);
}
AutumnEngine::TestScene::~TestScene(){}

void AutumnEngine::TestScene::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::UnloadAssets()
{
	std::cout << "unloading Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::Awake()
{

}

void AutumnEngine::TestScene::HandleInput(float dt)
{
	
}

void AutumnEngine::TestScene::Update(float dt)
{
	static_cast<float>(m_FPS = 1 / dt);
}

void AutumnEngine::TestScene::Render()
{
	Begin();

	End();
}