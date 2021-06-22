#pragma once
#include "../../Framework/BaseScene.h"
#include "../../Framework/GUILayer.h"
#include "../../Framework/Collision.h"

#include "SFML/Graphics.hpp"

namespace AutumnEngine
{
	class TestScene : public BaseScene
	{
		public:
			TestScene();
			TestScene(sf::RenderWindow& window, AutumnEngine::Input& input, AutumnEngine::GUILayer& guiManager);
			~TestScene();

			void Awake() override;
			void LoadAssets() override;
			void UnloadAssets() override;
			void HandleInput(float dt) override;
			void Update(float dt) override;
			void Render() override;

		private:
	};
}