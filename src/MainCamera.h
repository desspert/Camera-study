#pragma once
#include "ObjectBase.h"
#include "../vc2013/Input.h"

#define CAMERA MainCamera::get()

class MainCamera : public ObjectBase
{
private:
	CameraPersp camera;
	CameraOrtho camera_o;
	Vec2f camera_angle;
	Vec3f insert_point;
	Ray ray;
	int code;
	Matrix44f parent;
	Matrix44f parent_t;
	Matrix44f parent_r;
	float scatter;
public:
	MainCamera() : ObjectBase(Vec3f(0, 0, 0), Vec3f(1, 1, 1)) {};
	MainCamera(Vec3f _pos, Vec3f _size);
	void draw();
	void draw2d();
	void update();
	void setup(Vec3f _pos,Vec3f _size);
	void incliment_camera_angle(Vec2f mouse_vec)
	{
		
		camera_angle -= mouse_vec * 0.001;
		camera_angle.y = std::min(float(M_PI / 2) - 0.01f,
			std::max(camera_angle.y, -float(M_PI / 2) + 0.01f));
		camera_angle.x = std::fmod(camera_angle.x, M_PI * 2);
		
	}

	void cameraScatter(float sc) {
		scatter += sc;
	}

	Matrix44f getMatrix() {
		return parent;
	}
	Ray getRay() {
		return ray;
	}
	Vec3f getInsertPoint() {
		return insert_point;
	};
	void damage(int damage) {};
	static MainCamera& get() {
		static MainCamera cam;
		return cam;
	}
};

