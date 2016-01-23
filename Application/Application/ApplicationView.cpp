#include "ApplicationView.h"

ApplicationView::ApplicationView()
{
	toolbar = Toolbar(sf::Vector2f(0, 15), sf::Vector2f(float(WindowWidth), 40.f));
	toolbar.AddButton(std::make_shared<CImageButton>("Assets/Rectangle.png", "Rectangle"));
	toolbar.AddButton(std::make_shared<CImageButton>("Assets/Triangle.png", "Triangle"));
	toolbar.AddButton(std::make_shared<CImageButton>("Assets/Ellipse.png", "Ellipse"));
	toolbar.AddButton(std::make_shared<CImageButton>("Assets/Undo.png", "Undo"));
	toolbar.AddButton(std::make_shared<CImageButton>("Assets/Redo.png", "Redo"));
}


void ApplicationView::Draw(sf::RenderWindow & window)
{
	window.clear(sf::Color::White);
	toolbar.Draw(window);
	window.display();
}


void ApplicationView::ProcessVisualEvents(const sf::Event & event)
{
	toolbar.ProcessVisualEvents(event);
}

ApplicationView::~ApplicationView()
{
}

