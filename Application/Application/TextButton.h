#pragma once
#include "button.h"

namespace {
	const sf::Color TEXT_COLOR_NORMAL = sf::Color(0x22, 0x22, 0x22);
	const sf::Color TEXT_COLOR_HOVERED = sf::Color(0x00, 0x00, 0x00);
	const sf::Color TEXT_COLOR_PRESSED = sf::Color(0x40, 0x40, 0x40);
}
class CTextButton : public CButton
{
public:
	CTextButton();
	CTextButton(const SAssets & assets, const std::string & title);
	virtual void Draw(sf::RenderWindow& window) override;
	void SetTitle(std::string const& title);
	virtual ~CTextButton();

protected:
	sf::Text text;
	virtual void SetState(CButton::State newState);
};