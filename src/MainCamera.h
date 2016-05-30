#pragma once
#include "ObjectBase.h"


class MainCamera : public ObjectBase
{
private:
	CameraPersp camera;
	Vec2f camera_angle;
	Vec3f insert_point;
	

public:
	MainCamera(Vec3f _pos, Vec3f _size);
	void draw();
	void update();
	static float cameraMove(float incliment);
};

