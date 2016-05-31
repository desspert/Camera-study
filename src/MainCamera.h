#pragma once
#include "ObjectBase.h"
#include "../vc2013/Key.h"

class MainCamera : public ObjectBase
{
private:
	CameraPersp camera;
	Vec2f camera_angle;
	Vec3f insert_point;
	int code;
public:
	MainCamera(Vec3f _pos, Vec3f _size);
	void draw();
	void update();
	void cameraMove(KeyEvent event);
	void pullKey(KeyEvent event);
	void incliment_camera_angle(Vec2f mouse_vec)
	{
		
		camera_angle -= mouse_vec * 0.001;
		camera_angle.y = std::min(float(M_PI / 2) + 0.01f,
			std::max(camera_angle.y, -float(M_PI / 2) - 0.01f));
		camera_angle.x = std::fmod(camera_angle.x, M_PI * 2);
		
	}
};

