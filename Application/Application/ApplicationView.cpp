#include "ApplicationView.h"

ApplicationView::ApplicationView() 
{
	m_workspace = Workspace(sf::Vector2f((WindowWidth - 640) / 2.f, 100), sf::Vector2f(640, 480));
	m_toolbar = Toolbar(sf::Vector2f(0, 15), sf::Vector2f(float(WindowWidth), 40.f));
	m_toolbar.AddButton(std::make_shared<CImageButton>("Assets/Rectangle.png", "Rectangle"));
	m_toolbar.AddButton(std::make_shared<CImageButton>("Assets/Triangle.png", "Triangle"));
	m_toolbar.AddButton(std::make_shared<CImageButton>("Assets/Ellipse.png", "Ellipse"));
	m_toolbar.AddButton(std::make_shared<CImageButton>("Assets/Undo.png", "Undo"));
	m_toolbar.AddButton(std::make_shared<CImageButton>("Assets/Redo.png", "Redo"));
}


void ApplicationView::Draw(sf::RenderWindow & window)
{
	window.clear(sf::Color(238 ,238, 242));
	m_toolbar.Draw(window);
	m_workspace.Draw(window);
	window.display();
}


void ApplicationView::ProcessVisualEvents(const sf::Event & event)
{
	m_toolbar.ProcessVisualEvents(event);
}

Toolbar & ApplicationView::GetToolbar()
{
	return m_toolbar;
}

Workspace & ApplicationView::GetWorkspace()
{
	return m_workspace;
}

ApplicationView::~ApplicationView()
{
}

