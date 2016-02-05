#pragma once
#include "SFML/Graphics.hpp"
#include "BoundsObserver.h"
#include "boost/signals2.hpp"

enum Corners
{
	UpperLeft,
	UpperRight,
	BottomRight,
	BottomLeft
};

class Frame
{
public:
	Frame();
	~Frame();
	typedef boost::signals2::signal<void(sf::Vector2f)> DragSignal;
	typedef boost::signals2::signal<void()> ReleaseSignal;
	void SetPosition(const sf::Vector2f & pos);
	void SetSize(sf::Vector2f & size);
	std::shared_ptr<sf::RectangleShape>& GetPoint(Corners & corner);
	void SetVisible(bool flag);
	bool GetVisible();
	void Draw(sf::RenderWindow & window);
	sf::FloatRect GetGlobalBounds();
	void UpdateBounds(const sf::FloatRect & bounds);
	boost::signals2::connection& GetBoundsConnection();
	void HandleOnDrag(sf::Vector2f pos);
	void HandleOnRelease();
	boost::signals2::connection DoOnDrag(const DragSignal::slot_type & handler);
	boost::signals2::connection DoOnRelease(const ReleaseSignal::slot_type & handler);
	void ProcessEvents(sf::Event event);
	void DisconnectBounds();
private:
	bool m_firstClick;
	sf::Vector2f m_prevMousePos;
	sf::RectangleShape m_rect;
	std::vector<std::shared_ptr<sf::RectangleShape>> m_points;
	boost::signals2::scoped_connection m_boundsConnection;
	DragSignal m_onDrag;
	ReleaseSignal m_onRelease;
	bool m_isVisible;
	void SetPointsOnCorners(sf::FloatRect & rect);
};

