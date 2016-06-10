#include "Input.h"

InputAll::InputAll(){
	serch.insert(std::make_pair("Horizontal_WS", KeyEvent::KEY_w));
	serch.insert(std::make_pair("Horizontal_AD", KeyEvent::KEY_d));
}

void InputAll::keyDown(KeyEvent event) {
	press.insert(event.getCode());
	push.insert(event.getCode());
}
void InputAll::keyUp(KeyEvent event)
{
	pull.insert(event.getCode());
	press.erase(press.find(event.getCode()));
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



void InputAll::mouseDown(MouseEvent event)
{
	if (event.isLeft())
	{
		press.insert(MouseEvent::LEFT_DOWN);
		push.insert(MouseEvent::LEFT_DOWN);
	}
	if (event.isRight())
	{
		press.insert(MouseEvent::RIGHT_DOWN);
		push.insert(MouseEvent::RIGHT_DOWN);
	}
	if (event.isMiddle())
	{
		press.insert(MouseEvent::MIDDLE_DOWN);
		push.insert(MouseEvent::MIDDLE_DOWN);
	}
}

void InputAll::mouseUp(MouseEvent event)
{
	if (event.isLeft())
	{
		pull.insert(MouseEvent::LEFT_DOWN);
		press.erase(MouseEvent::LEFT_DOWN);
	}
	if (event.isRight())
	{
		pull.insert(MouseEvent::RIGHT_DOWN);
		press.erase(MouseEvent::RIGHT_DOWN);
	}
	if (event.isMiddle())
	{
		pull.insert(MouseEvent::MIDDLE_DOWN);
		press.erase(MouseEvent::MIDDLE_DOWN);
	}
}


float InputAll::getAxis(std::string axis_name_, const float & velocity_)
{
	if (serch.find(axis_name_) == serch.end())
		assert(!"Not axis name");
	int press_key = serch.find(axis_name_)->second;
	if (keys.find(press_key) == keys.end())
	{
		if (press_key == KeyEvent::KEY_RIGHT)
			keys.insert(std::make_pair(press_key, KeyEvent::KEY_LEFT));
		if (press_key == KeyEvent::KEY_UP)
			keys.insert(std::make_pair(press_key, KeyEvent::KEY_DOWN));
		if (press_key == KeyEvent::KEY_w)
			keys.insert(std::make_pair(press_key, KeyEvent::KEY_s));
		if (press_key == KeyEvent::KEY_d)
			keys.insert(std::make_pair(press_key, KeyEvent::KEY_a));
		axis_value.insert(std::make_pair(axis_name_, 0.0f));
	}
	else
	{
		if (pressKey(press_key))
		{
			axis_value.find(axis_name_)->second += velocity_;
			axis_value.find(axis_name_)->second = std::min(axis_value.find(axis_name_)->second, 1.0f);
		}
		else if (pressKey(keys.find(press_key)->second))
		{
			axis_value.find(axis_name_)->second -= velocity_;
			axis_value.find(axis_name_)->second = std::max(axis_value.find(axis_name_)->second, -1.0f);
		}
		else
		{
			if (axis_value.find(axis_name_)->second < 0)
				axis_value.find(axis_name_)->second += velocity_;
			if (axis_value.find(axis_name_)->second > 0)
				axis_value.find(axis_name_)->second -= velocity_;

			if (axis_value.find(axis_name_)->second < velocity_ &&
				axis_value.find(axis_name_)->second > -velocity_)
				axis_value.find(axis_name_)->second = 0;
		}
	}
	return axis_value.find(axis_name_)->second;
}

bool InputAll::pressKey(const int& pressed_key) {
	if (press.find(pressed_key) != press.end()) {
		return true;
	}
	return false;
}

bool InputAll::pushKey(const int & pressed_key)
{
	if (push.find(pressed_key) == push.end())
		return false;
	push.erase(push.find(pressed_key));
	return true;
}

bool InputAll::pullKey(const int & pressed_key)
{
	if (pull.find(pressed_key) == pull.end())
		return false;
	pull.erase(pull.find(pressed_key));
	return true;
}

void InputAll::flashInput()
{
	push.clear();
	pull.clear();
}






