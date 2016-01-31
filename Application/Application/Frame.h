#pragma once
#include "SFML/Graphics.hpp"
#include "BoundsObserver.h"
#include "boost/signals2/connection.hpp"

enum Corners
{
	UpperLeft,
	UpperRight,
	BottomRight,
	BottomLeft
};

class Frame : public IBoundsObserver
{
public:
	Frame();
	~Frame();

	void SetPosition(const sf::Vector2f & pos);
	void SetSize(sf::Vector2f & size);
	std::shared_ptr<sf::CircleShape>& GetPoint(Corners & corner);
	void SetVisible(bool flag);
	bool GetVisible();
	void Draw(sf::RenderWindow & window);
	sf::FloatRect GetGlobalBounds();
	void UpdateBounds(const sf::FloatRect & bounds)override;
	boost::signals2::connection& GetBoundsConnection()override;
private:
	sf::RectangleShape m_rect;
	std::vector<std::shared_ptr<sf::CircleShape>> m_points;
	boost::signals2::connection m_boundsConnection;
	bool m_isVisible;
	void SetPointsOnCorners(sf::FloatRect & rect);
};

