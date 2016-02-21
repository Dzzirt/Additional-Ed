#include "Frame.h"
#include "iostream"

using namespace std;

Frame::Frame() : m_firstClick(true), m_isVisible(false), m_isDrag(false), m_isResize(false), m_inResize(None)
{
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineThickness(1.f);
	m_rect.setOutlineColor(sf::Color::Black);
	for (size_t i = 0; i < 4; i++)
	{
		auto shape = std::make_shared<sf::RectangleShape>();
		shape->setSize(sf::Vector2f(6.f, 6.f));
		shape->setFillColor(sf::Color::Black);
		shape->setOrigin(shape->getSize() / 2.f);
		m_points.push_back(shape);
	}
}

void Frame::SetPosition(const sf::Vector2f & pos)
{
	m_rect.setPosition(pos);
}

void Frame::SetSize(sf::Vector2f const& size)
{
	m_rect.setSize(size);
}

std::shared_ptr<sf::RectangleShape>& Frame::GetPoint(Corners & corner)
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
	SetVisible(true);
	SetSize(sf::Vector2f(bounds.width, bounds.height));
	SetPosition(sf::Vector2f(bounds.left, bounds.top));
	SetPointsOnCorners(m_rect.getGlobalBounds());
}

boost::signals2::connection& Frame::GetBoundsConnection()
{
	return m_boundsConnection;
}

void Frame::HandleOnDrag(sf::Vector2f const& pos)
{
	m_onDrag(pos);
}

void Frame::HandleOnRelease()
{
	m_onRelease();
}

void Frame::HandleOnResize(sf::Vector2f const& mousePos, Corners corner)
{
	m_onResize(mousePos, corner);
}
boost::signals2::connection Frame::DoOnDrag(const DragSignal::slot_type & handler)
{
	return m_onDrag.connect(handler);
}

boost::signals2::connection Frame::DoOnRelease(const ReleaseSignal::slot_type & handler)
{
	return m_onRelease.connect(handler);
}

boost::signals2::connection Frame::DoOnResize(const ResizeSignal::slot_type & handler)
{
	return m_onResize.connect(handler);
}

void Frame::CheckAndDrag(sf::Vector2f mousePos)
{
	if (m_isDrag && m_inResize == None)
	{
		if (m_firstClick)
		{
			m_prevMousePos = mousePos;
			m_firstClick = false;
		}
		HandleOnDrag(mousePos - m_prevMousePos);
		m_prevMousePos = mousePos;
	}
}

void Frame::CheckAndResize(sf::Vector2f mousePos)
{
	if (m_inResize != None)
	{
		if (m_firstClick)
		{
			m_prevMousePos = mousePos;
			m_firstClick = false;
		}
		if (m_inResize == BottomLeft)
		{
			auto origin = sf::Vector2f(0.f, m_rect.getSize().y);
			HandleOnResize(mousePos - m_prevMousePos, BottomLeft);
		}
		else if (m_inResize == BottomRight)
		{
			auto origin = sf::Vector2f(m_rect.getSize());
			HandleOnResize(mousePos - m_prevMousePos, BottomRight);
		}
		else if (m_inResize == UpperLeft)
		{
			auto origin = sf::Vector2f(0.f, 0.f);
			HandleOnResize(mousePos - m_prevMousePos, UpperLeft);
		}
		else if (m_inResize == UpperRight)
		{
			auto origin = sf::Vector2f(m_rect.getSize().x, 0.f);
			HandleOnResize(mousePos - m_prevMousePos, UpperRight);
		}
		m_prevMousePos = mousePos;
	}
}
void Frame::ProcessEvents(sf::Event event)
{
	sf::Vector2f mousePos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
	for (size_t i = 0; i < m_points.size(); i++)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_points[i]->getGlobalBounds().contains(mousePos))
		{
			if (i == Corners::BottomLeft)
			{
				m_inResize = BottomLeft;
			}
			else if (i == Corners::BottomRight)
			{
				m_inResize = BottomRight;
			}
			else if (i == Corners::UpperLeft)
			{
				m_inResize = UpperLeft;
			}
			else if (i == Corners::UpperRight)
			{
				m_inResize = UpperRight;
			}
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_rect.getGlobalBounds().contains(mousePos))
	{
		m_isDrag = true;
		
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			m_firstClick = true;
			m_isDrag = false;
			m_inResize = None;
			HandleOnRelease();
		}
	}
	CheckAndDrag(mousePos);
	CheckAndResize(mousePos);

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


