#include "assets.h"

void SAssets::Init()
{
	fontMain.loadFromFile("Assets/DroidSans.ttf");
	buttonsImgPaths.push_back("Assets/Rectangle.png");
	buttonsImgPaths.push_back("Assets/Ellipse.png");
	buttonsImgPaths.push_back("Assets/Triangle.png");
	buttonsImgPaths.push_back("Assets/Undo.png");
	buttonsImgPaths.push_back("Assets/Redo.png");
}
