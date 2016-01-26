#include "Application.h"
#include "AppConsts.h"
Application::Application() 
	: controller(view)
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
			view.ProcessVisualEvents(event);
		}
		view.Draw(window);
	}
}
