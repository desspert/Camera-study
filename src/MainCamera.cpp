#include "MainCamera.h"

MainCamera::MainCamera(Vec3f _pos,Vec3f _size) : ObjectBase(_pos,_size){
	camera = CameraPersp(WINDOW_WIDTH, WINDOW_HEIGHT,
		// Ž‹–ìŠp
		60.0f,
		// near-z, far-z
		1.0f, 1000.0f);
	camera.setEyePoint(pos);
	camera.setCenterOfInterestPoint(Vec3f(0, 0.0f, 1000.0f));
}

void MainCamera::draw() {
	gl::setMatrices(camera);
}
void MainCamera::update() {
	insert_point.x = 1 * sin(camera_angle.x) * 1 * cos(camera_angle.y);
	insert_point.z = 1 * cos(camera_angle.x) * 1 * cos(camera_angle.y);
	insert_point.y = sin(camera_angle.y);

	camera.setEyePoint(pos + Vec3f(0, 1, 0));
	camera.setCenterOfInterestPoint(pos + insert_point + Vec3f(0, 1, 0));
	if (ENV.pressKey(KeyEvent::KEY_w)) {
		pos += Vec3f(0.02*sin(camera_angle.x), 0.0f, 0.02*cos(camera_angle.x));
	}
	if (ENV.pressKey(KeyEvent::KEY_a)) {
		pos.x += 0.02*cos(camera_angle.x);
		pos.z -= 0.02*sin(camera_angle.x);
	}
	if (ENV.pressKey(KeyEvent::KEY_s)) {
		pos -= Vec3f(0.02*sin(camera_angle.x), 0.0f, 0.02*cos(camera_angle.x));
	}
	if (ENV.pressKey(KeyEvent::KEY_d)) {
		pos.x -= 0.02*cos(camera_angle.x);
		pos.z += 0.02*sin(camera_angle.x);
	}
}

void MainCamera::setup(Vec3f _pos, Vec3f _size)
{
	pos = _pos;
	size = _size;
}





