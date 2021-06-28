#include "TestScene.h"

AutumnEngine::TestScene::TestScene() { m_AssetManager = nullptr; }
AutumnEngine::TestScene::TestScene(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiLayer, AutumnEngine::AssetManager& assetManager)
{
	SetRenderWindow(&window);
	SetGUILayer(&guiLayer);
	SetInput(&input);

	m_AssetManager = &assetManager;
}
AutumnEngine::TestScene::~TestScene(){}

void AutumnEngine::TestScene::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;

	m_AssetManager->LoadTexture("background", "Background", AutumnEngine::AssetManager::SpriteType::Texture, AutumnEngine::AssetManager::ImageFormat::PNG);

	std::cout << "Loaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::UnloadAssets()
{
	std::cout << "Unloading Assets -> " << GetSceneName() << std::endl;
	m_AssetManager->ClearAssets();
	std::cout << "Unloaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::Awake()
{
	GetGUILayer()->ClearComponents();

	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateSpriteUIElement(&m_AssetManager->GetTexture("Background"), "Background", { 0, 0 }, { 1920, 1080 }, sf::Color::White, 0));
	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateTextElement(&m_AssetManager->GetFont("MainFont"), "FPSText", "FPS: ", { 10, 10 }, 30, sf::Color::White));

	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::HandleInput(float dt)
{
	
}

void AutumnEngine::TestScene::Update(float dt)
{
	static_cast<int>(m_FPS = 1.f / dt);
	GetGUILayer()->GetUIComponent("FPSText").UpdateTextComponent("FPS: " + std::to_string(m_FPS));
}

void AutumnEngine::TestScene::Render()
{
	Begin();

	GetGUILayer()->Render(GetRenderWindow());

	End();
}