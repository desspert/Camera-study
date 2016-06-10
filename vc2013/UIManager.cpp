#include "UIManager.h"


void UIManager::setup()
{
	plate.push_back(std::make_shared<UIPlate>(Vec2f(446, 445), Vec2f(551, 550),"crosshair","crosshair.png"));
	plate.push_back(std::make_shared<UIPlate>(Vec2f(450, 400), Vec2f(850, 800), "hibana", "muzzle_flash.png"));
	trigger = false;
}

void UIManager::update() {

}

void UIManager::draw() {
	plate[0]->draw();
	
	if (trigger == true) {
		
		plate[1]->draw();
	}
	
}