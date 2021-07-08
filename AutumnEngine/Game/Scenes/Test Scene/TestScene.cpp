#include "TestScene.h"

AutumnEngine::TestScene::TestScene() { }
AutumnEngine::TestScene::TestScene(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiLayer, AutumnEngine::AssetManager& assetManager)
{
	SetRenderWindow(&window);
	SetGUILayer(&guiLayer);
	SetInput(&input);
	SetAssetManager(&assetManager);
}
AutumnEngine::TestScene::~TestScene(){}

void AutumnEngine::TestScene::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;

	GetAssetManager().LoadTexture("Resources/Sprites/Textures/background.png", "Background");
	GetAssetManager().LoadTexture("Resources/Sprites/UI/SliderBackground.png", "SliderBackground");
	GetAssetManager().LoadTexture("Resources/Sprites/UI/SliderHandle.png", "SliderHandle");

	std::cout << "Loaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::UnloadAssets()
{
	std::cout << "Unloading Assets -> " << GetSceneName() << std::endl;
	GetAssetManager().ClearAssets();
	std::cout << "Unloaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::Awake()
{
	GetGUILayer().ClearComponents();

	GetGUILayer().AddUIComponent(GetGUILayer().CreateSpriteUIElement(&GetAssetManager().GetTexture("Background"), "Background", { 0, 0 }, { 1920, 1080 }, sf::Color::White, 0));
	GetGUILayer().AddUIComponent(GetGUILayer().CreateTextElement(&GetAssetManager().GetFont("MainFont"), "FPSText", "FPS: ", { 10, 10 }, 30, sf::Color::White));

	GetGUILayer().AddUIComponent(GetGUILayer().CreateSliderElement(&GetAssetManager().GetTexture("SliderBackground"), &GetAssetManager().GetTexture("SliderHandle"), "TestSlider", { 300, 300 }, { 168, 19 }, { 15, 32 }, 0, 100, 1));

	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::HandleInput(float dt)
{

}

void AutumnEngine::TestScene::Update(float dt)
{
	m_FPS = 1.f / dt;
	GetGUILayer().GetUIComponent("FPSText").UpdateTextComponent("FPS: " + std::to_string(m_FPS));
}

void AutumnEngine::TestScene::Render()
{
	Begin();
	GetGUILayer().Render(GetRenderWindow());
	End();
}