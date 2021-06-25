#include "../Framework/GUI.h"

AutumnEngine::GUI::GUI() { }
AutumnEngine::GUI::~GUI(){}

AutumnEngine::Text* AutumnEngine::GUI::CreateTextElement(sf::Font* font, std::string componentName, std::string text, sf::Vector2f position, int characterSize, sf::Color colour)
{	
	AutumnEngine::Text* t_Text = new AutumnEngine::Text(font, componentName, text, position, characterSize, colour);
	return t_Text;
}

// Creation of Sprite Elements
AutumnEngine::Sprite* AutumnEngine::GUI::CreateSpriteUIElement(sf::Texture* t_Texture, std::string spriteName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
{
	AutumnEngine::Sprite* t_Sprite = new AutumnEngine::Sprite(t_Texture, spriteName, position, size, colour, layer);
	t_Sprite->SetComponentName(spriteName);
	t_Sprite->SetRenderingLayer(layer);

	return t_Sprite;
}
////

// Creation of Button Elements
AutumnEngine::Button* AutumnEngine::GUI::CreateButtonElement(sf::Texture* buttonIdle, sf::Texture* buttonHover, sf::Texture* buttonPressed, std::string componentName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
{
	AutumnEngine::Button* t_Button = new AutumnEngine::Button(buttonIdle, buttonHover, buttonPressed, componentName, position, size, colour, layer);
	t_Button->SetComponentName(componentName);
	t_Button->SetRenderingLayer(layer);

	return t_Button;
}
////

// Creation of Slider Elements
AutumnEngine::Slider* AutumnEngine::GUI::CreateSliderElement(std::string sliderBackgroundName, std::string sliderHandleName, std::string componentName, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize, sf::Vector2f handleSize, float min, float max, int layer)
{
	sf::Texture* BackgroundTexture = new sf::Texture();
	sf::Texture* Handletexture = new sf::Texture();

	if (!BackgroundTexture->loadFromFile("Resources/Sprites/" + sliderBackgroundName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << sliderBackgroundName << ".png" << std::endl;
	if (!Handletexture->loadFromFile("Resources/Sprites/" + sliderHandleName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << sliderHandleName << ".png" << std::endl;

	AutumnEngine::Slider* t_Slider = new AutumnEngine::Slider(BackgroundTexture, Handletexture, backgroundPosition, backgroundSize, handleSize, min, max, layer);
	t_Slider->SetComponentName(componentName);
	t_Slider->SetRenderingLayer(layer);

	return t_Slider;
}

// Creation of Toggle Elements
AutumnEngine::Toggle* AutumnEngine::GUI::CreateToggleElement(std::string toggleActiveSpriteName, std::string toggleDeactiveSpriteName, std::string componentName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
{
	sf::Texture* DeactiveTexture = new sf::Texture();
	sf::Texture* ActiveTexture = new sf::Texture();

	if (!DeactiveTexture->loadFromFile("Resources/Sprites/" + toggleDeactiveSpriteName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << toggleDeactiveSpriteName << ".png" << std::endl;
	if (!ActiveTexture->loadFromFile("Resources/Sprites/" + toggleActiveSpriteName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << toggleActiveSpriteName << ".png" << std::endl;

	AutumnEngine::Toggle* t_Toggle = new AutumnEngine::Toggle(DeactiveTexture, ActiveTexture, position, size, colour, layer);
	t_Toggle->SetComponentName(componentName);
	t_Toggle->SetRenderingLayer(layer);

	return t_Toggle;
}