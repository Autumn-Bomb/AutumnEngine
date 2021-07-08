#pragma once
#include "../../Framework/BaseScene/BaseScene.h"
#include "../../Framework/Layers/GUILayer/GUILayer.h"
#include "../../Framework/SceneManager/SceneManager.h"

#include "SFML/Graphics.hpp"

namespace AutumnEngine
{
	class Splashscreen : public BaseScene
	{
		public:
			Splashscreen();
			Splashscreen(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiManager, AutumnEngine::AssetManager& assetManager, AutumnEngine::SceneManager& sceneManager);
			~Splashscreen();

			void Awake() override;
			void LoadAssets() override;
			void UnloadAssets() override;
			void HandleInput(float dt) override;
			void Update(float dt) override;
			void Render() override;

		private:
			AutumnEngine::SceneManager* m_SceneManager;
			int m_Timer;
	};
}