#pragma once
#include "SFML/Graphics.hpp"
#include "../Sprite/Sprite.h"
#include "../Toggle/Toggle.h"
#include "../Slider/Slider.h"
#include "../Text/Text.h"
#include "../Button/Button.h"

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
			AutumnEngine::Text* CreateTextElement(sf::Font* font, std::string componentName, std::string text, sf::Vector2f position, int fontSize, sf::Color colour);

			// Creation and Updating of Sprite Elements
			AutumnEngine::Sprite* CreateSpriteUIElement(sf::Texture* t_Texture, std::string spriteName, sf::Vector2f position, sf::Vector2f size, sf::Color color, int layer);

			// Creation and Updating of Button Elements
			AutumnEngine::Button* CreateButtonElement(sf::Texture* buttonIdle, sf::Texture* buttonHover, sf::Texture* buttonPressed, std::string componentName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer);

			// Creation and Updating of Slider Elements
			AutumnEngine::Slider* CreateSliderElement(sf::Texture* sliderBackground, sf::Texture* sliderHandle, std::string componentName, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, float min, float max, int layer);

			// Creation and Updating of Toggle Elements
			AutumnEngine::Toggle* CreateToggleElement(std::string toggleActiveSpriteName, std::string toggleDeactiveSpriteName, std::string componentName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer);

		private:
	};
}