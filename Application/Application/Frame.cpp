#include "Frame.h"


Frame::Frame()
{

}
Frame::Frame(const sf::Vector2f & pos, sf::Vector2f & size)
{
	isVisible = false;
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(1.f);
	rect.setOutlineColor(sf::Color::Black);
	for (size_t i = 0; i < 4; i++)
	{
		points.push_back(sf::CircleShape());
	}
	for (auto & shape : points)
	{
		shape.setRadius(3.f);
		shape.setFillColor(sf::Color::Black);
		shape.setOrigin(shape.getRadius(), shape.getRadius());
	}
	SetPosition(pos);
	SetSize(size);
}

void Frame::SetPosition(const sf::Vector2f & pos)
{
	rect.setPosition(pos);
	SetPointsOnCorners(rect.getGlobalBounds());
}

void Frame::SetSize(sf::Vector2f & size)
{
	rect.setSize(size);
	SetPointsOnCorners(rect.getGlobalBounds());
}

sf::CircleShape Frame::GetPoint(Corners & corner)
{
	return points.at(corner);
}

void Frame::SetVisible(bool flag)
{
	isVisible = flag;
}

bool Frame::GetVisible()
{
	return isVisible;
}

void Frame::Draw(sf::RenderWindow & window)
{
	window.draw(rect);
	for (auto & point : points)
	{
		window.draw(point);
	}
}

sf::FloatRect Frame::GetGlobalBounds()
{
	return rect.getGlobalBounds();
}

void Frame::SetPointsOnCorners(sf::FloatRect & rect)
{
	points[UpperLeft].setPosition(rect.left, rect.top);
	points[UpperRight].setPosition(rect.left + rect.width, rect.top);
	points[BottomRight].setPosition(rect.left + rect.width, rect.top + rect.height);
	points[BottomLeft].setPosition(rect.left, rect.top + rect.height);
}

Frame::~Frame()
{
}


