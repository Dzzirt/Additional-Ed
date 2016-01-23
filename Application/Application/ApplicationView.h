#include "TextButton.h"
#include "ImageButton.h"
#include "Toolbar.h"
#include "assets.h"
#include "AppConsts.h"

class ApplicationView
{
public:
	ApplicationView(const SAssets & assets);
	ApplicationView();
	~ApplicationView();
	void Draw(sf::RenderWindow & window);
	void ProcessVisualEvents(const sf::Event & event);
private:
	Toolbar toolbar;

};


