#include "Toolbar.h"

Toolbar::Toolbar()
{
}

Toolbar::Toolbar(sf::Vector2f const& pos, sf::Vector2f const& size)
{
	m_bar.setFillColor(sf::Color(238, 238, 242));
	m_bar.setSize(size);
	m_bar.setPosition(pos);
}

void Toolbar::AddButton(const std::shared_ptr<CButton> & button)
{
	button->SetPosition(sf::Vector2f((m_bar.getPosition().x + m_bar.getSize().x / 20.f) * m_buttons.size() + m_bar.getSize().x / 40.f, m_bar.getPosition().y + m_bar.getSize().y / 2.f));
	m_buttons.push_back(button);
}

std::shared_ptr<CButton> Toolbar::GetButton(std::string name)
{
  for (auto & button : m_buttons)
  {
		if (button->GetName() == name)
		{
			return button;
		}
  }
	return nullptr;
}

void Toolbar::Draw(sf::RenderWindow & window)
{
	window.draw(m_bar);
	for (auto & button : m_buttons)
	{
		button->Draw(window);
	}
}

void Toolbar::SetSize(sf::Vector2f const& size)
{
	m_bar.setSize(size);
}

void Toolbar::SetPosition(sf::Vector2f const& point)
{
	m_bar.setPosition(point);
}

bool Toolbar::ProcessVisualEvents(sf::Event event, sf::RenderWindow & window)
{
	for (auto & button : m_buttons)
	{
		if (button->OnEvent(event))
		{
			return true;
		}
	}
	return false;
}

std::vector<std::shared_ptr<CButton>>& Toolbar::GetButtons()
{
	return m_buttons;
}

Toolbar::~Toolbar()
{
}
