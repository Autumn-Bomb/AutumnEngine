#include "../Framework/GUI.h"

AutumnEngine::GUI::GUI() { m_Font = nullptr; }
AutumnEngine::GUI::~GUI(){}

// Creation and Updating of Text Elements
void AutumnEngine::GUI::LoadFont(std::string fontName)
{
	m_Font = new sf::Font;
	if (!m_Font->loadFromFile("Resources/Font/" + fontName + ".ttf"))
	{
		std::cout << "Couldn't locate Font named: " << fontName << ".ttf" << std::endl;
	}
}

void AutumnEngine::GUI::CreateTextElement(const std::string fontName, const std::string text, sf::Vector2f position, const int characterSize, const sf::Color colour)
{	
	sf::Text* t_Text = new sf::Text;
	
	LoadFont(fontName);
	t_Text->setFont(*m_Font);
	t_Text->setCharacterSize(characterSize);
	t_Text->setPosition(position);
	t_Text->setFillColor(colour);

	m_TextElements.push_back(*t_Text);

	// TODO - Delete created text object once added to vector
	delete t_Text;
	t_Text = nullptr;
}

void AutumnEngine::GUI::UpdateTextElement(const int index, std::string text)
{
	GetTextElement(index).setString(text);
}
void AutumnEngine::GUI::UpdateTextElement(const int index, int text)
{
	GetTextElement(index).setString(std::to_string(text));
}
////

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

// Creation and updating of Button Elements
void AutumnEngine::GUI::CreateButtonElement(const std::string textureName, const std::string spriteName, const sf::Vector2f position, const sf::Vector2f size, const sf::Color colour, const int layer)
{
	sf::Texture* t_Texture = new sf::Texture();
	if (!t_Texture->loadFromFile("Resources/Sprites/" + textureName + ".png"))
		std::cout << "Couldn't locate Sprite named: " << textureName << ".png" << std::endl;

	AutumnEngine::Sprite t_Sprite = AutumnEngine::Sprite(t_Texture, spriteName, position, size, colour, layer);
	m_SpriteElements.push_back(t_Sprite);
}
////

// Creation and Updating of Slider Elements
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