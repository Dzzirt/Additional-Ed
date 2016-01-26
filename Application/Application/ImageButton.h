#pragma once
#include "button.h"

class CImageButton : public CButton
{
public:
	CImageButton();
	CImageButton(const std::string & texturePath, const std::string & name);
	virtual ~CImageButton();
	virtual void Draw(sf::RenderWindow &window) override;
	void SetTexture(const std::string & path);
protected:
	sf::Texture * texture;
	sf::Sprite sprite;
};