#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "string"
#include "boost/signals2.hpp"
#include "ButtonClickObservable.h"

using namespace boost::signals2;
namespace {
	
	const sf::Color BACK_COLOR_NORMAL = sf::Color(238, 238, 242);
	const sf::Color BACK_COLOR_HOVERED = sf::Color(201, 222, 245);
	const sf::Color BACK_COLOR_PRESSED = sf::Color(0, 122, 204);
	const sf::Color BORDER_COLOR_NORMAL = sf::Color(0x80, 0xD0, 0x80);
	const sf::Color BORDER_COLOR_HOVERED = sf::Color(0x92, 0xE0, 0x92);
	const sf::Color BORDER_COLOR_PRESSED = sf::Color(0x50, 0xA0, 0x50);
	const float BORDER_WIDTH = 0.f;
}

struct SAssets;

class CButton : public IButtonClickObservable
{
public:
	CButton();
	CButton(sf::Vector2f const& pos, sf::Vector2f const& size, std::string const& name);
	virtual ~CButton();
	CButton(const CButton &)= delete;
	void SetPosition(sf::Vector2f const& point);
	void SetSize(sf::Vector2f const& size);
	bool OnEvent(sf::Event const& event);
	virtual void Draw(sf::RenderWindow &window);
	virtual std::string GetName();
	void RegisterObserver(IButtonClickObserver & o)override;
	void DeleteObserver(IButtonClickObserver & o)override;
	void Notify()override;
	std::function<void()> handler;
protected:
	enum class State
	{
		Normal,
		Hovered,
		Pressed
	};
	signal<void(std::string)> onClick;
	std::string m_name;
	sf::RectangleShape shape;
	State state;
	bool DoesHit(sf::Vector2f const& point) const;
	virtual void SetState(State newState);
};