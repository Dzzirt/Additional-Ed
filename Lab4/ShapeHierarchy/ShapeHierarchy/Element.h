#pragma once
#include "Visitor.h"

class IElement {
public:
	virtual void Accept(IVisitor & visitor) = 0;
	virtual ~IElement() = default;
};