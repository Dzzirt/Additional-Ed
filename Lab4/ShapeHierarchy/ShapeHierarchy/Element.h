#pragma once

class IVisitor;

class IElement {
public:
	virtual void Accept(IVisitor & visitor) = 0;
	virtual ~IElement() = default;
};