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
	GetAssetManager().CreateTextureAtlas("Resources/Sprites/TextureAtlases/WorldAtlas.jpg", "WorldAtlas");
	GetAssetManager().CreateSpriteSheet("Resources/Sprites/SpriteSheets/BasicSpritesheet.png", "SpriteSheet");

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

	m_WorldAtlas = &GetAssetManager().GetTextureAtlas("WorldAtlas");
	m_WorldAtlas->AddTexture(sf::IntRect(144, 114, 63, 29), sf::Vector2f(100, 100));
	m_WorldAtlas->AddTexture(sf::IntRect(50, 64, 44, 16), sf::Vector2f(200, 100));
	m_WorldAtlas->AddTexture(sf::IntRect(112, 49, 47, 63), sf::Vector2f(300, 100));
	m_WorldAtlas->Batch();

	m_SpriteSheet = &GetAssetManager().GetSpriteSheet("SpriteSheet");
	m_SpriteSheet->AddSprite(sf::IntRect(131, 39, 49, 53), sf::Vector2f(300, 400));
	m_SpriteSheet->Batch();

	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::TestScene::HandleInput(float dt)
{
	if (GetInput().IsKeyDown(sf::Keyboard::Escape))
		GetRenderWindow()->close();
}

void AutumnEngine::TestScene::Update(float dt)
{
	m_FPS = 1.f / dt;
	GetGUILayer().GetUIComponent("FPSText").UpdateTextComponent("FPS: " + std::to_string(m_FPS));
}

void AutumnEngine::TestScene::Render()
{
	GetGUILayer().Render();
	m_WorldAtlas->Render(GetRenderWindow());
	m_SpriteSheet->Render(GetRenderWindow());
}