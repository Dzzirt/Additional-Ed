#include "Frame.h"
#include "iostream"

Frame::Frame()
{
	m_isVisible = false;
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineThickness(1.f);
	m_rect.setOutlineColor(sf::Color::Black);
	for (size_t i = 0; i < 4; i++)
	{
		m_points.push_back(std::make_shared<sf::CircleShape>());
	}
	for (auto & shape : m_points)
	{
		shape->setRadius(3.f);
		shape->setFillColor(sf::Color::Black);
		shape->setOrigin(shape->getRadius(), shape->getRadius());
	}
}

void Frame::SetPosition(const sf::Vector2f & pos)
{
	m_rect.setPosition(pos);
}

void Frame::SetSize(sf::Vector2f & size)
{
	m_rect.setSize(size);
}

std::shared_ptr<sf::CircleShape>& Frame::GetPoint(Corners & corner)
{
	return m_points.at(corner);
}

void Frame::SetVisible(bool flag)
{
	m_isVisible = flag;
}

bool Frame::GetVisible()
{
	return m_isVisible;
}

void Frame::Draw(sf::RenderWindow & window)
{
	if (m_isVisible)
	{
		window.draw(m_rect);
		for (auto & point : m_points)
		{
			window.draw(*point);
		}
	}
	
}

sf::FloatRect Frame::GetGlobalBounds()
{
	return m_rect.getGlobalBounds();
}

void Frame::UpdateBounds(const sf::FloatRect & bounds)
{
	std::cout << bounds.left << " " << bounds.top << std::endl;
	SetVisible(true);
	SetSize(sf::Vector2f(bounds.width, bounds.height));
	SetPosition(sf::Vector2f(bounds.left, bounds.top));
	SetPointsOnCorners(m_rect.getGlobalBounds());
}

boost::signals2::connection& Frame::GetBoundsConnection()
{
	return m_boundsConnection;
}

void Frame::SetPointsOnCorners(sf::FloatRect & rect)
{
	m_points[UpperLeft]->setPosition(rect.left, rect.top);
	m_points[UpperRight]->setPosition(rect.left + rect.width, rect.top);
	m_points[BottomRight]->setPosition(rect.left + rect.width, rect.top + rect.height);
	m_points[BottomLeft]->setPosition(rect.left, rect.top + rect.height);
}

Frame::~Frame()
{
}


