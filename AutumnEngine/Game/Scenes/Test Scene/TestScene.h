#pragma once
#include "../../Framework/BaseScene.h"

#include "SFML/Graphics.hpp"
#include "../../Framework/GUI.h"

namespace AutumnEngine
{
	class TestScene : public BaseScene
	{
		public:
			TestScene();
			TestScene(sf::RenderWindow* target);
			~TestScene();

			void Awake() override;
			void LoadAssets() override;
			void UnloadAssets() override;
			void HandleInput(float dt) override;
			void Update(float dt) override;
			void Render() override;

		private:
			AutumnEngine::GUI m_GUIManager;
	};
}