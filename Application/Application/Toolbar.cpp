#include "Toolbar.h"

Toolbar::Toolbar()
{
}

Toolbar::Toolbar(sf::Vector2f const& pos, sf::Vector2f const& size)
{
	bar.setFillColor(sf::Color(238, 238, 242));
	bar.setSize(size);
	bar.setPosition(pos);
}

void Toolbar::AddButton(const std::shared_ptr<CButton> & button)
{
	button->SetPosition(sf::Vector2f((bar.getPosition().x + bar.getSize().x / 20.f) * buttons.size() + bar.getSize().x / 40.f, bar.getPosition().y + bar.getSize().y / 2.f));
	buttons.push_back(button);
}

void Toolbar::Draw(sf::RenderWindow & window)
{
	window.draw(bar);
	for (auto & button : buttons)
	{
		button->Draw(window);
	}
}

void Toolbar::SetSize(sf::Vector2f const& size)
{
	bar.setSize(size);
}

void Toolbar::SetPosition(sf::Vector2f const& point)
{
	bar.setPosition(point);
}

void Toolbar::ProcessVisualEvents(sf::Event event)
{
	for (auto & button : buttons)
	{
		button->OnEvent(event);
	}
}

Toolbar::~Toolbar()
{
}
