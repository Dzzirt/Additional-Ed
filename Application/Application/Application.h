#include "ApplicationController.h"
#include "ApplicationView.h"
#include "ApplicationModel.h"
#include "vld.h"

class Application
{
public:
	Application();
	~Application();
	void Exec();
private:
	std::shared_ptr<ApplicationModel> m_appModel;
	std::shared_ptr<ApplicationView> m_view;
	std::shared_ptr<ApplicationController> m_controller;
};