#include "../Framework/GUI.h"

AutumnEngine::GUI::GUI() { }
AutumnEngine::GUI::~GUI(){}

AutumnEngine::Text* AutumnEngine::GUI::CreateTextElement(const std::string fontName, const std::string text, const std::string componentName, sf::Vector2f position, const int characterSize, const sf::Color colour)
{	
	AutumnEngine::Text* t_Text = new AutumnEngine::Text(fontName, text, position, characterSize, colour);
	t_Text->SetComponentName(componentName);

	return t_Text;
}

// Creation of Sprite Elements
AutumnEngine::Sprite* AutumnEngine::GUI::CreateSpriteUIElement(const std::string textureName, const std::string spriteName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	sf::Texture* t_Texture = new sf::Texture();
	if (!t_Texture->loadFromFile("Resources/Sprites/" + textureName + ".png"))
		std::cout << "Couldn't locate Font named: " << textureName << ".png" << std::endl;

	AutumnEngine::Sprite* t_Sprite = new AutumnEngine::Sprite(t_Texture, spriteName, position, size, colour, layer);
	t_Sprite->SetComponentName(spriteName);
	t_Sprite->SetRenderingLayer(layer);

	return t_Sprite;
}
////

// Creation of Button Elements
AutumnEngine::Button* AutumnEngine::GUI::CreateButtonElement(const std::string idleTextureName, const std::string hoverTextureName, const std::string pressedTextureName, const std::string componentName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	sf::Texture* t_TextureIdle = new sf::Texture();
	sf::Texture* t_TextureHover = new sf::Texture();
	sf::Texture* t_TexturePressed = new sf::Texture();

	if (!t_TextureIdle->loadFromFile("Resources/Sprites/" + idleTextureName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << idleTextureName << ".png" << std::endl;

	if (!t_TextureHover->loadFromFile("Resources/Sprites/" + hoverTextureName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << hoverTextureName << ".png" << std::endl;

	if (!t_TexturePressed->loadFromFile("Resources/Sprites/" + pressedTextureName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << pressedTextureName << ".png" << std::endl;

	AutumnEngine::Button* t_Button = new AutumnEngine::Button(t_TextureIdle, t_TextureHover, t_TexturePressed, componentName, position, size, colour, layer);
	t_Button->SetComponentName(componentName);
	t_Button->SetRenderingLayer(layer);

	return t_Button;
}
////

// Creation of Slider Elements
AutumnEngine::Slider* AutumnEngine::GUI::CreateSliderElement(std::string sliderBackgroundName, std::string sliderHandleName, const std::string componentName, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize,  sf::Vector2f handleSize, const float min, const float max, const int layer)
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
AutumnEngine::Toggle* AutumnEngine::GUI::CreateToggleElement(std::string toggleActiveSpriteName, std::string toggleDeactiveSpriteName, const std::string componentName, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
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