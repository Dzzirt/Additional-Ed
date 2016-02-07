#pragma once
#include "ShapeVisual.h"
#include "CanvasClickObservable.h"

class Workspace
{
public:
	typedef boost::signals2::signal<void()> WorkSpaceClickSignal;
	Workspace();
	Workspace(const sf::Vector2f & pos, sf::Vector2f & size);
	~Workspace();

	void AddShape(std::shared_ptr<ShapeVisual> & shape, size_t index);
	void RemoveSelectedShape();
	void RemoveShape(size_t index);
	void Draw(sf::RenderWindow & window);
	size_t GetShapesCount();
	std::vector<std::shared_ptr<ShapeVisual>>& GetShapesVisual();
	sf::RectangleShape& GetCanvasVisual();
	void ProcessEvents(sf::Event event);
	boost::signals2::connection DoOnClick(const WorkSpaceClickSignal::slot_type & handler);
	size_t GetShapeIndex(const ShapeVisual & shapeVisual);
	void HandleClick();
private:
	std::vector<std::shared_ptr<ShapeVisual>> m_shapesVisual;
	sf::RectangleShape m_canvasVisual;
	WorkSpaceClickSignal m_onClick;
};
