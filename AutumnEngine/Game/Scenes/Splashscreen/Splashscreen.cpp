#include "Splashscreen.h"

AutumnEngine::Splashscreen::Splashscreen() { m_SceneManager = nullptr; }
AutumnEngine::Splashscreen::Splashscreen(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiLayer, AutumnEngine::AssetManager& assetManager, AutumnEngine::SceneManager& sceneManager)
{
	SetRenderWindow(&window);
	SetGUILayer(&guiLayer);
	SetInput(&input);
	SetAssetManager(&assetManager);

	m_SceneManager = &sceneManager;
}
AutumnEngine::Splashscreen::~Splashscreen() {}

void AutumnEngine::Splashscreen::LoadAssets()
{
	std::cout << "Loading Assets -> " << GetSceneName() << std::endl;

	GetAssetManager()->LoadTexture("background", "Background", AutumnEngine::AssetManager::SpriteType::Texture, AutumnEngine::AssetManager::ImageFormat::PNG);
	GetAssetManager()->LoadTexture("companyLogo", "Logo", AutumnEngine::AssetManager::SpriteType::Texture, AutumnEngine::AssetManager::ImageFormat::PNG);

	std::cout << "Loaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::Splashscreen::UnloadAssets()
{
	std::cout << "Unloading Assets -> " << GetSceneName() << std::endl;
	GetAssetManager()->ClearAssets();
	std::cout << "Unloaded Assets -> " << GetSceneName() << std::endl;
}

void AutumnEngine::Splashscreen::Awake()
{
	GetGUILayer()->ClearComponents();

	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateSpriteUIElement(&GetAssetManager()->GetTexture("Background"), "Background", { 0, 0 }, { 1920, 1080 }, sf::Color::White, 0));
	GetGUILayer()->AddUIComponent(GetGUILayer()->GetGUIManager().CreateSpriteUIElement(&GetAssetManager()->GetTexture("Logo"), "Logo", { 600, 300 }, { 500, 500 }, sf::Color::White, 0));

	std::cout << "Awake Initialised -> " << GetSceneName() << std::endl;
}

void AutumnEngine::Splashscreen::HandleInput(float dt)
{

}

void AutumnEngine::Splashscreen::Update(float dt)
{
	static_cast<int>(m_FPS = 1.f / dt);
	m_Timer++;

	std::cout << "Splash Timer: " << std::to_string(m_Timer) << std::endl;

	if (m_Timer == 100)
	{
		m_SceneManager->ChangeScene("Main Menu");
	}
}

void AutumnEngine::Splashscreen::Render()
{
	Begin();

	GetGUILayer()->Render(GetRenderWindow());

	End();
}