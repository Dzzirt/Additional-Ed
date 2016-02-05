#pragma once
#include "SFML/Graphics/Rect.hpp"
#include "AppConsts.h"
#include "boost/signals2.hpp"


class ShapeLogic
{
public:
	typedef boost::signals2::signal<void(sf::FloatRect, sf::Vector2f)> BoundsChangeSignal;
	ShapeLogic(sf::FloatRect const& bounds, ShapeType type, size_t index);
	~ShapeLogic();
	void SetSize(sf::Vector2f const& size);
	void SetPosition(sf::Vector2f const& pos);
	void SetSelected(bool flag);
	void SetIndex(size_t index);
	ShapeType GetType();
	sf::FloatRect GetBounds();
	sf::Vector2f GetPosition();
	sf::Vector2f GetSize();
	size_t GetIndex();
	void HandleChange();
	boost::signals2::connection DoOnChange(const BoundsChangeSignal::slot_type & handler);
	void SetOrigin(const sf::Vector2f & pos);
private:
	size_t m_index;
	sf::FloatRect m_bounds;
	sf::Vector2f m_origin;
	ShapeType m_type;
	bool m_isSelect;
	BoundsChangeSignal m_onChange;
};

