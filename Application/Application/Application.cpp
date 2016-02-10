#include "Application.h"
#include "AppConsts.h"
#include "iostream"

Application::Application() 
	:	m_appModel(std::make_shared<ApplicationModel>(std::make_shared<DomainModel>())),
		m_view(std::make_shared<ApplicationView>()),
		m_controller(std::make_shared<ApplicationController>(m_appModel, m_view))
{
}

Application::~Application()
{

}

void Application::Exec()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "App", sf::Style::Default, settings);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			m_view->ProcessVisualEvents(event);
		}
		m_view->Draw(window);
	}
}
