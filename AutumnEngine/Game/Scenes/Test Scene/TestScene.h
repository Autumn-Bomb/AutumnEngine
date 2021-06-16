#pragma once
#include "../../Framework/BaseScene.h"
#include "../../Framework/GUI.h"
#include "../../Framework/Entity.h"

#include "SFML/Graphics.hpp"

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
			AutumnEngine::Entity m_Entity;
	};
}