#include "ImageButton.h"
#include "ButtonsConsts.h"
#include "cassert"
#include "iostream"
CImageButton::CImageButton(const std::string & texturePath, const std::string & name)
	: CButton(DEFAULT_BUTTON_POS, DEFAULT_BUTTON_SIZE, name)
{
	texture = new sf::Texture();
	texture->loadFromFile(texturePath);
	texture->setSmooth(true);
	sprite.setTexture(*texture);
}

CImageButton::CImageButton() : CButton()
{

}

CImageButton::~CImageButton()
{

}

void CImageButton::Draw(sf::RenderWindow &window)
{

	sf::Vector2u textureBounds = texture->getSize();
	sprite.setOrigin(0.5f * textureBounds.x, 0.5f * textureBounds.y);
	sprite.setPosition(shape.getPosition());
	window.draw(shape);
	window.draw(sprite);
}

void CImageButton::SetTexture(const std::string & path)
{
	texture->loadFromFile(path);
}
