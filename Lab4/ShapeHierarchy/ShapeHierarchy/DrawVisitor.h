#pragma once
#include "Visitor.h"
#include <memory>

class CDrawVisitor : public IVisitor
{
public:
	void Visit(CLineSegment & line) override;
	void Visit(CTriangle & triangle) override;
	void Visit(CRectangle & rectangle) override;
	void Visit(CCircle & circle) override;
	void Draw(sf::RenderWindow & window);
private:
	std::unique_ptr<sf::Drawable> m_drawable;
};

