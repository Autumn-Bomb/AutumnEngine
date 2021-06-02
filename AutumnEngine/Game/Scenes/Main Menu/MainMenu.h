#pragma once

#include "../../Framework/BaseScene.h"

namespace AutumnEngine
{
	class MainMenu : public BaseScene
	{
		public:
			MainMenu();
			MainMenu(sf::RenderWindow* target);
			~MainMenu();

			void Awake();
			void LoadAssets() override;
			void UnloadAssets() override;
			void HandleInput(float dt) override;
			void Update(float dt) override;
			void Render() override;

		private:
	};
}