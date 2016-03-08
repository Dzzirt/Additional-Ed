#pragma once
#include "SFML/Graphics.hpp"
#include "BoundsObserver.h"
#include "boost/signals2.hpp"

enum Corners
{
	UpperLeft,
	UpperRight,
	BottomRight,
	BottomLeft,
	None
};

class Frame
{
public:
	Frame();
	~Frame();
	typedef boost::signals2::signal<void(sf::Vector2f)> DragSignal;
	typedef boost::signals2::signal<void()> ReleaseSignal;
	typedef boost::signals2::signal<void(sf::Vector2f, Corners)> ResizeSignal;
	void SetPosition(const sf::Vector2f & pos);
	void SetSize(sf::Vector2f const& size);

	std::shared_ptr<sf::RectangleShape>& GetPoint(Corners & corner);
	void SetVisible(bool flag);
	bool GetVisible();
	sf::FloatRect GetGlobalBounds();

	void Draw(sf::RenderWindow & window);
	void UpdateBounds(const sf::FloatRect & bounds);
	boost::signals2::connection& GetBoundsConnection();

	boost::signals2::connection DoOnDrag(const DragSignal::slot_type & handler);
	boost::signals2::connection DoOnRelease(const ReleaseSignal::slot_type & handler);
	boost::signals2::connection DoOnResize(const ResizeSignal::slot_type & handler);

	
	void HandleOnDrag(sf::Vector2f const& pos);
	void HandleOnRelease();
	void HandleOnResize(sf::Vector2f const& mousePos, Corners corner);

	bool ProcessEvents(sf::Event event, sf::RenderWindow & window);

	

private:
	bool m_firstClick;
	sf::Vector2f m_prevMousePos;
	sf::RectangleShape m_rect;
	std::vector<std::shared_ptr<sf::RectangleShape>> m_points;
	boost::signals2::scoped_connection m_boundsConnection;
	DragSignal m_onDrag;
	ReleaseSignal m_onRelease;
	ResizeSignal m_onResize;
	Corners m_inResize;
	bool m_isVisible;
	bool m_isDrag;
	bool m_isResize;
	void SetPointsOnCorners(sf::FloatRect & rect);
	bool CheckAndDrag(sf::Vector2f mousePos);
	bool CheckAndResize(sf::Vector2f mousePos);
};

