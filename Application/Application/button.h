#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

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

class CButton
{
public:
	CButton();
	CButton(sf::Vector2f const& pos, sf::Vector2f const& size);
	virtual ~CButton();
	CButton(const CButton &)= delete;
	void SetPosition(sf::Vector2f const& point);
	void SetSize(sf::Vector2f const& size);
	bool OnEvent(sf::Event const& event);
	virtual void Draw(sf::RenderWindow &window);

	std::function<void()> handler;
protected:
	enum class State
	{
		Normal,
		Hovered,
		Pressed
	};

	bool DoesHit(sf::Vector2f const& point) const;
	virtual void SetState(State newState);

	sf::RectangleShape shape;
	State state;

};