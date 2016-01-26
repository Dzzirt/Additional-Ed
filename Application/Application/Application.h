#include "ApplicationController.h"

class Application
{
public:
	Application();
	~Application();
	void Exec();
protected:
private:
	ApplicationView view;
	ApplicationController controller;
};