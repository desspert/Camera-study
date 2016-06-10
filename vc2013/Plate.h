#pragma once
#include "MaterialBase.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "../vc2013/Texture.h"
#include "cinder/svg/Svg.h"
using namespace ci;
using namespace ci::app;

class UIPlate : AppNative
{
private:
	std::string name;
	
	
	Vec2f pos;
	Vec2f end_pos;
public:
	UIPlate(Vec2f _pos, Vec2f _end_pos,std::string name,std::string path) :
		pos(_pos), end_pos(_end_pos) {
		TEX.set(name, path);
		this->name = name;
		
	}

	Vec2f getPos() {
		return pos;
	}
	
	void setPos() {

	}
	void setSize() {

	}

	void update();
	void draw();
	
};