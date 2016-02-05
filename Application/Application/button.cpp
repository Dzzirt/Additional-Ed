#include "button.h"
#include "assets.h"

using namespace sf;


void CButton::SetSize(Vector2f const& size)
{
	shape.setSize(size - 2.f * Vector2f(BORDER_WIDTH, BORDER_WIDTH));
}

bool CButton::DoesHit(sf::Vector2f const& point) const
{
	return shape.getGlobalBounds().contains(point);
}

void CButton::SetPosition(const Vector2f& point)
{
	shape.setPosition(BORDER_WIDTH + point.x, BORDER_WIDTH + point.y);
}

void CButton::Draw(RenderWindow& window)
{
	window.draw(shape);
}


std::string CButton::GetName()
{
	return m_name;
}

CButton::CButton(sf::Vector2f const& pos, Vector2f const& size, std::string const& name) : m_name(name)
{
	shape.setOutlineThickness(BORDER_WIDTH);
	SetSize(size);
	shape.setOrigin(shape.getSize() / 2.f);
	SetPosition(pos);
	SetState(State::Normal);
}


CButton::CButton()
{

}

bool CButton::OnEvent(const Event& event)
{
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

void CButton::SetState(CButton::State newState)
{
	state = newState;
	switch (newState)
	{
	case State::Normal:
		shape.setFillColor(BACK_COLOR_NORMAL);
		shape.setOutlineColor(BORDER_COLOR_NORMAL);
		break;
	case State::Hovered:
		shape.setFillColor(BACK_COLOR_HOVERED);
		shape.setOutlineColor(BORDER_COLOR_HOVERED);
		break;
	case State::Pressed:
		shape.setFillColor(BACK_COLOR_PRESSED);
		shape.setOutlineColor(BORDER_COLOR_PRESSED);
		break;
	}
}

void CButton::HandleOnClick()
{
	onClick(m_name);
}

boost::signals2::connection CButton::DoOnClick(const ButtonClickSignal::slot_type & handler)
{
	return onClick.connect(handler);
}

CButton::~CButton()
{

}

