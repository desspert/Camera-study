#include "Input.h"

InputAll::InputAll(){
	serch.insert(std::make_pair("Horizontal_WS", KeyEvent::KEY_w));
	serch.insert(std::make_pair("Horizontal_AD", KeyEvent::KEY_d));
}

void InputAll::keyDown(KeyEvent event) {
	press.insert(event.getCode());
}
void InputAll::mouseMove(MouseEvent event)
{

	inc_pos = Vec2f(mouse_pos.x - event.getX(), mouse_pos.y - event.getY());

	if (mouse_pos != Vec2f(444, 416)) {
		CAMERA.incliment_camera_angle(inc_pos);
	}
	mouse_pos = event.getPos();

	const double ScaleX = 0xffff / GetSystemMetrics(SM_CXSCREEN);
	const double ScaleY = 0xffff / GetSystemMetrics(SM_CYSCREEN);

	INPUT input = {};
	input.type = INPUT_MOUSE;
	input.mi.dx = (LONG)(1000 * ScaleX);
	input.mi.dy = (LONG)(500 * ScaleY);
	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

	SendInput(1, &input, sizeof(INPUT));
	mouse_pos = event.getPos();
	inc_pos = Vec2f(0, 0);


}
void InputAll::mouseDrag(MouseEvent event)
{

	const double ScaleX = 0xffff / GetSystemMetrics(SM_CXSCREEN);
	const double ScaleY = 0xffff / GetSystemMetrics(SM_CYSCREEN);
	INPUT input = {};

	input.type = INPUT_MOUSE;
	input.mi.dx = (LONG)(1000 * ScaleX);
	input.mi.dy = (LONG)(500 * ScaleY);
	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

	SendInput(1, &input, sizeof(INPUT));

}
void InputAll::keyUp(KeyEvent event)
{
	press.erase(press.find(event.getCode()));
}

void InputAll::mouseDown(MouseEvent event)
{
}


bool InputAll::pressKey(int pressed_key) {
	if (press.find(pressed_key) != press.end()) {
		return true;
	}
	return false;
}




