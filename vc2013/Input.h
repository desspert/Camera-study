#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"        // ライティング
#include "cinder/gl/Material.h"     // マテリアル(材質)
#include "../src/MainCamera.h"
#include <iostream>
#include <unordered_map>
#include <set>

using namespace ci;
using namespace ci::app;
#define ENV InputAll::get()
class InputAll : public AppNative
{
private:
	std::set<int> press;
	std::set<int> push;
	std::set<int> pull;
	Vec2f mouse_pos;
	Vec2f inc_pos;
	bool mouse_left_press;
	bool mouse_right_press;
	
public:
	InputAll();
	static InputAll& get() {
		static InputAll in;
		return in;
	}

	Vec2f getIncPos() {
		return inc_pos;
	}
	void setIncPos(Vec2f set) {
		inc_pos = set;
	}

	void keyDown(KeyEvent event) override;
	void keyUp(KeyEvent event) override;
	void mouseDown(MouseEvent event) override;
	void mouseUp(MouseEvent event) override;
	void mouseMove(MouseEvent event) override;
	void mouseDrag(MouseEvent event) override;

	
	

	std::unordered_map<std::string, int> serch;
	std::unordered_map<int, int> keys;
	std::unordered_map<std::string, float> axis_value;
	float getAxis(std::string axis_name, const float& velocity = 0.3);
	

	bool pressKey(const int& pressed_key);
	bool pushKey(const int& pressed_key);
	bool pullKey(const int& pressed_key);

	void flashInput();
};