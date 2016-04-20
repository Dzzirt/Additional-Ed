#pragma once

class CLineSegment;
class CTriangle;
class CRectangle;
class CCircle;
class IVisitor
{
public:
	virtual void Visit(CLineSegment & line) = 0;
	virtual void Visit(CTriangle & triangle) = 0;
	virtual void Visit(CRectangle & rectangle) = 0;
	virtual void Visit(CCircle & circle) = 0;
	virtual ~IVisitor() = default;
};

