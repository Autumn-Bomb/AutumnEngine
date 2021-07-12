#include "Splashscreen.h"

AutumnEngine::Splashscreen::Splashscreen() { m_SceneManager = nullptr; m_Timer = 0; }
AutumnEngine::Splashscreen::Splashscreen(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiLayer, AutumnEngine::AssetManager& assetManager, AutumnEngine::SceneManager& sceneManager)
{
	SetRenderWindow(&window);
	SetGUILayer(&guiLayer);
	SetInput(&input);
	SetAssetManager(&assetManager);

	m_Timer = 0;
	m_SceneManager = &sceneManager;
}
AutumnEngine::Splashscreen::~Splashscreen() {}

void AutumnEngine::Splashscreen::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;

	GetAssetManager().LoadTexture("Resources/Sprites/Textures/background.png", "Background");
	GetAssetManager().LoadTexture("Resources/Sprites/Textures/companyLogo.png", "Logo");

	std::cout << "Loaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::Splashscreen::UnloadAssets()
{
	std::cout << "Unloading Assets -> " << GetSceneName() << std::endl;
	GetAssetManager().ClearAssets();
	std::cout << "Unloaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::Splashscreen::Awake()
{
	GetGUILayer().ClearComponents();

	GetGUILayer().AddUIComponent(GetGUILayer().CreateSpriteUIElement(&GetAssetManager().GetTexture("Background"), "Background", { 0, 0 }, { 1920, 1080 }, sf::Color::White, 0));
	GetGUILayer().AddUIComponent(GetGUILayer().CreateSpriteUIElement(&GetAssetManager().GetTexture("Logo"), "Logo", { 600, 300 }, { 500, 500 }, sf::Color::White, 0));

	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::Splashscreen::HandleInput(float dt)
{

}

void AutumnEngine::Splashscreen::Update(float dt)
{
	m_FPS = 1.f / dt;
	m_Timer++;

	if (m_Timer == 100)
	{
		m_SceneManager->SwitchState(AutumnEngine::GameState::gameState::MAINMENU);
	}
}

void AutumnEngine::Splashscreen::Render()
{
	GetGUILayer().Render(GetRenderWindow());
}