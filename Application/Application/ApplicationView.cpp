#include "ApplicationView.h"
#include "iostream"
ApplicationView::ApplicationView() 
{
	m_workspace = std::make_shared<Workspace>(sf::Vector2f((WindowWidth - 640) / 2.f, 100), sf::Vector2f(640, 480));
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
	m_workspace->Draw(window);
	m_frame.Draw(window);
	window.display();
}
//Chain of responsibility
//Events Interface
void ApplicationView::ProcessVisualEvents(const sf::Event & event, sf::RenderWindow & window)
{
	if (!m_toolbar.ProcessVisualEvents(event, window))
	{
		if (!m_frame.ProcessEvents(event, window))
		{
			m_workspace->ProcessEvents(event, window);
		}
	}
}

Toolbar & ApplicationView::GetToolbar()
{
	return m_toolbar;
}

Workspace & ApplicationView::GetWorkspace()
{
	return *m_workspace;
}

Frame & ApplicationView::GetFrame()
{
	return m_frame;
}

ApplicationView::~ApplicationView()
{
}

