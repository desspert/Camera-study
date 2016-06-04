#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
using namespace ci;
using namespace ci::app;

class Envent : public AppNative
{
private:
	static Vec2f mouse_move_pos;
	static Vec2f mouse_drag_pos;
	static int get_key;
public:
	void mouseMove(MouseEvent event) {
		mouse_move_pos.x = event.getX();
		mouse_move_pos.y = event.getY();
	}
	
};
