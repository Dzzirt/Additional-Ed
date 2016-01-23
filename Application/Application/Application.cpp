#include "Application.h"
#include "AppConsts.h"
Application::Application()
{

}

Application::~Application()
{

}

void Application::Exec()
{
	sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Application");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			view.ProcessVisualEvents(event);
		}
		view.Draw(window);
	}
}
