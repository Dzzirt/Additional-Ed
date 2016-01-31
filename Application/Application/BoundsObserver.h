#pragma once
#include "SFML/Graphics.hpp"
#include "boost/signals2/connection.hpp"

class IBoundsObserver
{
public:
	virtual void UpdateBounds(const sf::FloatRect & bounds) = 0;
	virtual boost::signals2::connection& GetBoundsConnection() = 0;
};