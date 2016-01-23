#pragma once
#include <vector>
#include "button.h"
#include "ImageButton.h"
#include "memory"

class Toolbar
{
public:
	Toolbar();
	Toolbar(sf::Vector2f const& pos, sf::Vector2f const& size);
	~Toolbar();

	void AddButton(const std::shared_ptr<CButton> & button);
	void Draw(sf::RenderWindow & window);
	void SetSize(sf::Vector2f const& size);
	void SetPosition(sf::Vector2f const& point);
	void ProcessVisualEvents(sf::Event event);
private:
	std::vector<std::shared_ptr<CButton>> buttons;
	sf::RectangleShape bar;
};

