#include "../Framework/GUI.h"

AutumnEngine::GUI::GUI() { }
AutumnEngine::GUI::~GUI(){}

void AutumnEngine::GUI::CreateTextElement(const std::string fontName, const std::string text, sf::Vector2f position, const int characterSize, const sf::Color colour)
{	
	AutumnEngine::Text* t_Text = new AutumnEngine::Text(fontName, text, position, characterSize, colour);
	m_TextElements.push_back(*t_Text);
}

// Creation of Sprite Elements
void AutumnEngine::GUI::CreateSpriteUIElement(const std::string textureName, const std::string spriteName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	sf::Texture* t_Texture = new sf::Texture();
	if (!t_Texture->loadFromFile("Resources/Sprites/" + textureName + ".png"))
		std::cout << "Couldn't locate Font named: " << textureName << ".png" << std::endl;

	AutumnEngine::Sprite* t_Sprite = new AutumnEngine::Sprite(t_Texture, spriteName, position, size, colour, layer);
	m_SpriteElements.push_back(*t_Sprite);

	delete t_Sprite;
	t_Sprite = nullptr;
}
////

// Creation of Button Elements
void AutumnEngine::GUI::CreateButtonElement(const std::string idleTextureName, const std::string hoverTextureName, const std::string pressedTextureName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
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

	AutumnEngine::Button* t_Button = new AutumnEngine::Button(t_TextureIdle, t_TextureHover, t_TexturePressed, position, size, colour, layer);
	m_ButtonElements.push_back(*t_Button);

	delete t_Button;
	t_Button = nullptr;
}
////

// Creation of Slider Elements
void AutumnEngine::GUI::CreateSliderElement(std::string sliderBackgroundName, std::string sliderHandleName, sf::Vector2f backgroundPosition, sf::Vector2f backgroundSize,  sf::Vector2f handleSize, const float min, const float max)
{
	sf::Texture* BackgroundTexture = new sf::Texture();
	sf::Texture* Handletexture = new sf::Texture();

	if (!BackgroundTexture->loadFromFile("Resources/Sprites/" + sliderBackgroundName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << sliderBackgroundName << ".png" << std::endl;
	if (!Handletexture->loadFromFile("Resources/Sprites/" + sliderHandleName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << sliderHandleName << ".png" << std::endl;

	AutumnEngine::Slider* t_Slider = new AutumnEngine::Slider(BackgroundTexture, Handletexture, backgroundPosition, backgroundSize, handleSize, min, max);
	m_SliderElements.push_back(*t_Slider);

	delete t_Slider;
	t_Slider = nullptr;
}

// Creation of Toggle Elements
void AutumnEngine::GUI::CreateToggleElement(std::string toggleDeactiveSprite, std::string toggleActiveSprite, sf::Vector2f position, sf::Vector2f size, sf::Color colour, int layer)
{
	sf::Texture* DeactiveTexture = new sf::Texture();
	sf::Texture* ActiveTexture = new sf::Texture();

	if (!DeactiveTexture->loadFromFile("Resources/Sprites/" + toggleDeactiveSprite + ".png"))
		std::cout << "Couldn't locate Sprite named: " << toggleDeactiveSprite << ".png" << std::endl;
	if (!ActiveTexture->loadFromFile("Resources/Sprites/" + toggleActiveSprite + ".png"))
		std::cout << "Couldn't locate Sprite named: " << toggleActiveSprite << ".png" << std::endl;

	AutumnEngine::Toggle* t_Toggle = new AutumnEngine::Toggle(DeactiveTexture, ActiveTexture, position, size, colour, layer);
	m_ToggleElements.push_back(*t_Toggle);

	delete t_Toggle;
	t_Toggle = nullptr;
}