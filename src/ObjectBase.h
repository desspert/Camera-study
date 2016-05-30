#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"        // ライティング
#include "cinder/gl/Material.h"     // マテリアル(材質)
#include "cinder/Camera.h"

using namespace ci;
using namespace ci::app;
using namespace std;
enum {
	WINDOW_WIDTH = 1000,
	WINDOW_HEIGHT = 1000,
};

class ObjectBase : public AppNative {
public:
	ObjectBase(Vec3f _pos, Vec3f _size) :
		pos(_pos),
		size(_size) {}
	Vec3f getPos() {
		return pos;
	}
	Vec3f getSize() {
		return size;
	}
	void setPos(Vec3f _pos) {
		pos = _pos;
	}
	void setSize(Vec3f _size) {
		pos = _size;
	}
protected:
	
	Vec3f pos;
	Vec3f size;



};