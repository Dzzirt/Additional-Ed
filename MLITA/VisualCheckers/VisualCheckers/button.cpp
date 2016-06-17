#include "stdafx.h"
#include "button.h"


using namespace sf;


namespace {
const int TITLE_TEXT_SIZE = 12;
const sf::Color TEXT_COLOR_NORMAL = Color(130, 81, 0);
const sf::Color TEXT_COLOR_HOVERED = Color(130, 81, 0);
const sf::Color TEXT_COLOR_PRESSED = Color(130, 81, 0);
const sf::Color BACK_COLOR_NORMAL = Color(254, 205, 114);
const sf::Color BACK_COLOR_HOVERED = Color(254, 218, 150);
const sf::Color BACK_COLOR_PRESSED = Color(220, 170, 100);
const sf::Color BORDER_COLOR_NORMAL = Color(170, 85, 0);
const sf::Color BORDER_COLOR_HOVERED = Color(185, 92, 0);
const sf::Color BORDER_COLOR_PRESSED = Color(155, 70, 0);
const float BORDER_WIDTH = 3.f;
}


void SCustomButton::Init(sf::Font const& font, const std::string& title)
{
	text.setFont(font);
	text.setCharacterSize(TITLE_TEXT_SIZE);
	text.setString(title);
	shape.setOutlineThickness(BORDER_WIDTH);
	text.setStyle(sf::Text::Bold);
	SetSize(CUSTOM_BUTTON_SIZE);
	SetPosition(Vector2f(0, 0));
	SetState(State::Normal);
}

void SCustomButton::SetTitle(std::string const& title)
{
	text.setString(title);
}

void SCustomButton::SetSize(Vector2f const& size)
{
	shape.setSize(size - 2.f * Vector2f(BORDER_WIDTH, BORDER_WIDTH));
}

bool SCustomButton::DoesHit(sf::Vector2f const& point) const
{
	return shape.getGlobalBounds().contains(point);
}

void SCustomButton::SetPosition(const Vector2f& point)
{
	shape.setPosition(BORDER_WIDTH + point.x, BORDER_WIDTH + point.y);
}


void SCustomButton::SetVisible(bool flag)
{
	isVisible = flag;
}

void SCustomButton::Draw(RenderWindow& window)
{
	if (isVisible)
	{
		FloatRect textBounds = text.getLocalBounds();
		text.setOrigin(0.5f * textBounds.width, textBounds.height);
		text.setPosition(shape.getPosition() + 0.5f * shape.getSize());
		window.draw(shape);
		window.draw(text);
	}

}

bool SCustomButton::OnEvent(const Event& event)
{
	if (!isVisible)
	{
		return false;
	}
	auto mouseButtonHits = [&]() {
		Vector2f mousePoint(float(event.mouseButton.x), float(event.mouseButton.y));
		return (event.mouseButton.button == sf::Mouse::Left) && DoesHit(mousePoint);
	};
	auto mouseMoveHits = [&]() {
		Vector2f mousePoint(float(event.mouseMove.x), float(event.mouseMove.y));
		return DoesHit(mousePoint);
	};

	switch (event.type) {
	case sf::Event::MouseMoved:
		if (state != State::Pressed)
		{
			SetState(mouseMoveHits() ? State::Hovered : State::Normal);
		}
		break;
	case sf::Event::MouseButtonPressed:
		if (mouseButtonHits())
		{
			SetState(State::Pressed);
			return true;
		}
		break;
	case sf::Event::MouseButtonReleased:
		if (state == State::Pressed)
		{
			SetState(mouseButtonHits() ? State::Hovered : State::Normal);
			if (handler)
			{
				handler();
			}
			return true;
		}
		break;
	case sf::Event::MouseLeft:
		SetState(State::Normal);
		break;
	default:
		break;
	}

	return false;
}

void SCustomButton::SetState(SCustomButton::State newState)
{
	state = newState;
	switch (newState)
	{
	case State::Normal:
		text.setColor(TEXT_COLOR_NORMAL);
		shape.setFillColor(BACK_COLOR_NORMAL);
		shape.setOutlineColor(BORDER_COLOR_NORMAL);
		break;
	case State::Hovered:
		text.setColor(TEXT_COLOR_HOVERED);
		shape.setFillColor(BACK_COLOR_HOVERED);
		shape.setOutlineColor(BORDER_COLOR_HOVERED);
		break;
	case State::Pressed:
		text.setColor(TEXT_COLOR_PRESSED);
		shape.setFillColor(BACK_COLOR_PRESSED);
		shape.setOutlineColor(BORDER_COLOR_PRESSED);
		break;
	}
}
