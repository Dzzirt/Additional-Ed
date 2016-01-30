#pragma once
#include "SFML/System/Vector2.hpp"
#include "AppConsts.h"
#include "boost/signals2.hpp"



using namespace boost::signals2;

class ShapeLogic 
{
public:
	ShapeLogic(sf::Vector2f const& pos, sf::Vector2f const& size, ShapeType type);
	~ShapeLogic();
	void SetSize(sf::Vector2f const& size);
	void SetPosition(sf::Vector2f const& pos);
	ShapeType GetType();
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	signal<void(sf::Vector2f, sf::Vector2f)> m_onChange;
private:
	sf::Vector2f m_pos;
	sf::Vector2f m_size;
	ShapeType m_type;
	bool m_isSelect;

};

