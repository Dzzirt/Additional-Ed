#pragma once
#include "SFML/Graphics.hpp"
#include "memory"
#include "AppConsts.h"
#include "EllipseShape.h"
#include "Frame.h"
#include "BoundsObserver.h"
#include "boost/signals2.hpp"
#include "ShapeClickObservable.h"

class ShapeVisual : public IBoundsObserver, public IShapeClickObservable
{
public:
	ShapeVisual();
	ShapeVisual(std::shared_ptr<sf::ConvexShape> & shape);
	ShapeVisual(std::shared_ptr<sf::RectangleShape> & shape);
	ShapeVisual(std::shared_ptr<EllipseShape> & shape);
	~ShapeVisual();

	void SetPosition(const sf::Vector2f & pos);
	void SetSize(const sf::Vector2f & size);
	void SetIndex(size_t index);
	void Draw(sf::RenderWindow & window);
	void UpdateBounds(const sf::FloatRect & bounds)override;
	boost::signals2::connection& GetBoundsConnection()override;
	void ProcessEvents(sf::Event event);
	void RegisterObserver(IShapeClickObserver & o)override;
	void DeleteObserver(IShapeClickObserver & o)override;
	void Notify()override;
private:
	sf::FloatRect m_bounds;
	std::shared_ptr<sf::Shape> m_shape;
	boost::signals2::signal<void(size_t)> m_onClick;
	boost::signals2::connection m_boundsConnection;
	size_t m_index;
};

