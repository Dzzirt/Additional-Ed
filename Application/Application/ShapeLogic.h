#pragma once
#include "SFML/Graphics/Rect.hpp"
#include "AppConsts.h"
#include "boost/signals2.hpp"
#include "BoundsObservable.h"


class ShapeLogic : public IBoundsObservable
{
public:
	ShapeLogic(sf::Vector2f const& pos, sf::Vector2f const& size, ShapeType type);
	~ShapeLogic();
	void SetSize(sf::Vector2f const& size);
	void SetPosition(sf::Vector2f const& pos);
	void SetSelected(bool flag);
	ShapeType GetType();
	sf::FloatRect GetBounds();
	void Notify();
	void RegisterObserver(IBoundsObserver & o);
	void DeleteObserver(IBoundsObserver & o);
private:
	sf::FloatRect m_bounds;
	ShapeType m_type;
	bool m_isSelect;
	boost::signals2::signal<void(sf::FloatRect)> m_onChange;
};

