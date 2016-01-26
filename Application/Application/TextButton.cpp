#include "TextButton.h"
#include "assets.h"
#include "ButtonsConsts.h"

CTextButton::CTextButton(const SAssets & assets, const std::string & title) 
	: CButton(DEFAULT_BUTTON_POS, DEFAULT_BUTTON_SIZE, title)
{
	text.setFont(assets.fontMain);
	text.setCharacterSize(DEFAULT_TEXT_SIZE);
	text.setString(title);
	text.setStyle(sf::Text::Bold);
}

CTextButton::CTextButton() : CButton()
{

}

CTextButton::~CTextButton()
{

}

void CTextButton::SetTitle(std::string const& title)
{
	text.setString(title);
}

void CTextButton::Draw(sf::RenderWindow& window)
{
	sf::FloatRect textBounds = text.getLocalBounds();
	text.setOrigin(0.5f * textBounds.width, textBounds.height);
	text.setPosition(shape.getPosition() + 0.5f * shape.getSize());
	window.draw(shape);
	window.draw(text);
}

void CTextButton::SetState(CButton::State newState)
{
	state = newState;
	switch (newState)
	{
	case State::Normal:
		text.setColor(TEXT_COLOR_NORMAL);
		shape.setFillColor(BACK_COLOR_NORMAL);
		shape.setOutlineColor(BORDER_COLOR_NORMAL);
		break;
	case State::Hovered:
		text.setColor(TEXT_COLOR_HOVERED);
		shape.setFillColor(BACK_COLOR_HOVERED);
		shape.setOutlineColor(BORDER_COLOR_HOVERED);
		break;
	case State::Pressed:
		text.setColor(TEXT_COLOR_PRESSED);
		shape.setFillColor(BACK_COLOR_PRESSED);
		shape.setOutlineColor(BORDER_COLOR_PRESSED);
		break;
	}
}