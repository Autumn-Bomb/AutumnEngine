#pragma once
#include "SFML/Graphics.hpp"
#include "Sprite.h"
#include "Toggle.h"
#include "Slider.h"
#include "Text.h"
#include "Button.h"

#include <string>
#include <vector>
#include <iostream>

namespace AutumnEngine
{
	class GUI
	{
		public:
			GUI();
			~GUI();

			// Creation and Updating of Text Elements
			AutumnEngine::Text* CreateTextElement(const std::string fontName, const std::string text, const std::string componentName, sf::Vector2f position, const int fontSize, const sf::Color colour);

			// Creation and Updating of Sprite Elements
			AutumnEngine::Sprite* CreateSpriteUIElement(const std::string textureName, const std::string spriteName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color color, const int layer);

			// Creation and Updating of Button Elements
			AutumnEngine::Button* CreateButtonElement(const std::string idleTextureName, const std::string hoverTextureName, const std::string pressedTextureName, const std::string componentName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer);

			// Creation and Updating of Slider Elements
			AutumnEngine::Slider* CreateSliderElement(std::string sliderBackgroundName, std::string sliderHandleName, const std::string componentName, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, const float min, const float max, const int layer);

			// Creation and Updating of Toggle Elements
			AutumnEngine::Toggle* CreateToggleElement(std::string toggleActiveSpriteName, std::string toggleDeactiveSpriteName, const std::string componentName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer);

		private:
	};
}