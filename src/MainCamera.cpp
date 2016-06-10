#include "MainCamera.h"

MainCamera::MainCamera(Vec3f _pos,Vec3f _size) : ObjectBase(_pos,_size){
	camera = CameraPersp(WINDOW_WIDTH, WINDOW_HEIGHT,
		// 視野角
		60.0f,
		// near-z, far-z
		1.0f, 1000.0f);
	camera.setEyePoint(pos);
	camera.setCenterOfInterestPoint(Vec3f(0, 0.0f, 1000.0f));
	scatter = 0;
	

	parent = Matrix44f::identity();
	Matrix44f parent_t = Matrix44f::createTranslation(Vec3f(0.0f, 0.0f, 0.0f));
	
}

void MainCamera::draw() {
	gl::setMatrices(camera);

	// TIPS:深度バッファとカリングの設定をここでおこなっている
	gl::enableDepthRead();
	gl::enableDepthWrite();
	gl::enable(GL_CULL_FACE);
}
void MainCamera::draw2d()
{
	gl::setMatrices(camera_o);

	// TIPS:深度バッファとカリングの設定をここでおこなっている
	gl::disableDepthRead();
	gl::disableDepthWrite();
	gl::disable(GL_CULL_FACE);
}
void MainCamera::update() {
	if (scatter <= 0) {
		scatter = 0;
	}
	scatter -= 0.05f;
	insert_point.x = 1 * sin(camera_angle.x) * 1 * cos(camera_angle.y);
	insert_point.z = 1 * cos(camera_angle.x) * 1 * cos(camera_angle.y);
	insert_point.y = sin(camera_angle.y);

	camera.setEyePoint(pos + Vec3f(0, 1, 0 ) - Vec3f(scatter*sin(camera_angle.x), 0.0f, scatter*cos(camera_angle.x)));
	camera.setCenterOfInterestPoint(pos + insert_point + Vec3f(0, 1 , 0) - Vec3f(scatter*sin(camera_angle.x), 0.0f, scatter*cos(camera_angle.x)));
	ray.setOrigin(pos + Vec3f(0, 1, 0) - Vec3f(scatter*sin(camera_angle.x), 0.0f, scatter*cos(camera_angle.x)));
	ray.setDirection(insert_point * (1000, 1000, 1000) + Vec3f(0, 1 , 0) - Vec3f(scatter*sin(camera_angle.x), 0.0f, scatter*cos(camera_angle.x)));
	
	Matrix44f parent_r = Matrix44f::createRotation(Vec3f(0, 0,0));
	parent = parent_t*parent_r;
	if (ENV.pressKey(KeyEvent::KEY_w)) {
		pos += Vec3f(0.1*sin(camera_angle.x), 0.0f, 0.1*cos(camera_angle.x));
	}
	if (ENV.pressKey(KeyEvent::KEY_a)) {
		pos.x += 0.1*cos(camera_angle.x);
		pos.z -= 0.1*sin(camera_angle.x);
	}
	if (ENV.pressKey(KeyEvent::KEY_s)) {
		pos -= Vec3f(0.1*sin(camera_angle.x), 0.0f, 0.1*cos(camera_angle.x));
	}
	if (ENV.pressKey(KeyEvent::KEY_d)) {
		pos.x -= 0.1*cos(camera_angle.x);
		pos.z += 0.1*sin(camera_angle.x);
	}
}

void MainCamera::setup(Vec3f _pos, Vec3f _size)
{
	pos = _pos;
	size = _size;
	camera_o = CameraOrtho(0, WINDOW_WIDTH,        // 画面左の座標、画面右の座標
		WINDOW_HEIGHT, 0,       // 画面下端の座標、画面上端の座標
		1, 10);                 // 画面手前の座標、画面奥の座標

	camera_o.setEyePoint(Vec3f(0.0f, 0.0f, 0.0f));
	camera_o.setCenterOfInterestPoint(Vec3f(0.0f, 0.0f, -1000.0f));
	gl::enableAlphaBlending();
}





