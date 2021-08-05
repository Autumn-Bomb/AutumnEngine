#pragma once
#include "../../Framework/BaseScene/BaseScene.h"
#include "../../Framework/Layers/GUILayer/GUILayer.h"
#include "../../../Framework/Collision/Collision.h"
#include "../../../Framework/TextureAtlas/TextureAtlas.h"

#include "SFML/Graphics.hpp"

namespace AutumnEngine
{
	class TestScene : public BaseScene
	{
		public:
			TestScene();
			TestScene(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiManager, AutumnEngine::AssetManager& assetManager);
			~TestScene();
	
			void Awake() override;
			void LoadAssets() override;
			void UnloadAssets() override;
			void HandleInput(float dt) override;
			void Update(float dt) override;
			void Render() override;

		private:
			//AutumnEngine::TextureAtlas* m_WorldAtlas;
	};
}