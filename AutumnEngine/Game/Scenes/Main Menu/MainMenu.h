#pragma once

#include "../../Framework/BaseScene.h"
#include "../../Framework/Collision.h"
#include "../../Framework/SceneManager.h"

namespace AutumnEngine
{
	class MainMenu : public BaseScene
	{
		public:
			MainMenu();
			MainMenu(sf::RenderWindow& target, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiLayer, AutumnEngine::SceneManager& sceneManager, AutumnEngine::AssetManager& m_AssetManager);
			~MainMenu();

			void Awake();
			void LoadAssets() override;
			void UnloadAssets() override;
			void HandleInput(float dt) override;
			void Update(float dt) override;
			void Render() override;

		private:
			AutumnEngine::SceneManager* m_SceneManager;
			AutumnEngine::AssetManager* m_AssetManager;
	};
}