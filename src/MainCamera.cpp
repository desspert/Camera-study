#include "MainCamera.h"

MainCamera::MainCamera(Vec3f _pos,Vec3f _size) : ObjectBase(_pos,_size){
	camera = CameraPersp(WINDOW_WIDTH, WINDOW_HEIGHT,
		// Ž‹–ìŠp
		60.0f,
		// near-z, far-z
		1.0f, 500.0f);
	camera.setEyePoint(pos);
	camera.setCenterOfInterestPoint(Vec3f(0, 0.0f, 1000.0f));
	
}

void MainCamera::draw() {
	gl::setMatrices(camera);
}
void MainCamera::update() {
	/*insert_point.x = 1 * sin(camera_angle.x) * 1 * cos(camera_angle.y);
	insert_point.z = 1 * cos(camera_angle.x) * 1 * cos(camera_angle.y);
	insert_point.y = sin(camera_angle.y);

	camera.setEyePoint(pos);
	camera.setCenterOfInterestPoint(pos + insert_point);*/
}

