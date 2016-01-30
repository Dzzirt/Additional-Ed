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
	std::shared_ptr<CButton> GetButton(std::string name);
	void Draw(sf::RenderWindow & window);
	void SetSize(sf::Vector2f const& size);
	void SetPosition(sf::Vector2f const& point);
	void ProcessVisualEvents(sf::Event event);
	std::vector<std::shared_ptr<CButton>>& GetButtons();
private:
	std::vector<std::shared_ptr<CButton>> m_buttons;
	sf::RectangleShape m_bar;
};

