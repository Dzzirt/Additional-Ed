#pragma once
#include "SFML/Graphics.hpp"
#include "memory"
#include "AppConsts.h"
#include "EllipseShape.h"
#include "Frame.h"
#include "boost/signals2.hpp"

class ShapeVisual
{
public:
	typedef boost::signals2::signal<void(size_t)> ButtonClickSignal;

	ShapeVisual();
	ShapeVisual(std::shared_ptr<sf::ConvexShape> & shape);
	ShapeVisual(std::shared_ptr<sf::RectangleShape> & shape);
	ShapeVisual(std::shared_ptr<EllipseShape> & shape);
	~ShapeVisual();

	void SetPosition(const sf::Vector2f & pos);
	void SetSize(const sf::Vector2f & size);
	void SetIndex(size_t index);
	void SetVisible(bool flag);
	size_t GetIndex();
	bool GetVisible();
	void Draw(sf::RenderWindow & window);
	void UpdateBounds(const sf::FloatRect & bounds, const sf::Vector2f & origin);
	boost::signals2::connection& GetBoundsConnection();
	void ProcessEvents(sf::Event event);
	boost::signals2::connection DoOnClick(const ButtonClickSignal::slot_type & handler);
	void HandleOnClick();
	void SetOrigin(const sf::Vector2f & origin);
private:
	bool m_isVisible;
	sf::FloatRect m_bounds;
	std::shared_ptr<sf::Shape> m_shape;
	ButtonClickSignal m_onClick;
	boost::signals2::scoped_connection m_boundsConnection;
	size_t m_index;
};

