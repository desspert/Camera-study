#include "GameMain.h"

GameMain::GameMain()
{
}



void GameMain::setup()
{
	
	CAMERA.setup(Vec3f(0,0,-10),Vec3f(1,2,1));
	const double ScaleX = 0xffff / GetSystemMetrics(SM_CXSCREEN);
	const double ScaleY = 0xffff / GetSystemMetrics(SM_CYSCREEN);

	INPUT input = {};
	input.type = INPUT_MOUSE;
	input.mi.dx = (LONG)(1000 * ScaleX);
	input.mi.dy = (LONG)(500 * ScaleY);
	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

	SendInput(1, &input, sizeof(INPUT));
	ENV.setIncPos(Vec2f(0, 0));
	material.setup(CAMERA.getPos());
	ui.setup();
}




void GameMain::update()
{


	
	material.update();
	CAMERA.update();
}

void GameMain::draw()
{
	
	CAMERA.draw();
	 
	gl::clear(Color(0.5, 0.5, 0.5));
	material.draw();
	ui.setTrigger(material.getTrigger());
	CAMERA.draw2d();
	ui.draw();
	
}

void GameMain::shift()
{

}