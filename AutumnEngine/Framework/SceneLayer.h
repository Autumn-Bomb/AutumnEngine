#pragma once

#include "SFML/Graphics.hpp"
#include "SceneManager.h"

namespace AutumnEngine
{
	class SceneLayer
	{
	public:
		SceneLayer();
		SceneLayer(sf::Vector2f position, sf::Vector2f size);

		void Awake();
		void Update(float dt);
		void Render(sf::RenderWindow* window);

		private:
			AutumnEngine::SceneManager m_SceneManager;
			sf::View m_SceneCamera;
	};
}