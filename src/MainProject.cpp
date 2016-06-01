#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"        // ライティング
#include "cinder/gl/Material.h"     // マテリアル(材質)
#include "cinder/Camera.h"
#include "ObjectBase.h"
#include "MainCamera.h"
#include "../vc2013/MaterialsManager.h"
#include "../vc2013/Key.h"

class MainProject : public AppNative {
private:
	MainCamera* camera;
	MaterialManager material;
	Vec2f mouse_pos;
	Vec2f inc_pos;
	Vec2f inc_pos2;
  public:
	  

	void prepareSettings(Settings* settings);
	void setup();
	void mouseMove( MouseEvent event ) override;
	void mouseDrag(MouseEvent event) override;
	void update();
	void keyDown(KeyEvent event) override;
	void keyUp(KeyEvent event) override;
	void draw();
};

void MainProject::prepareSettings(Settings* settings) {
	settings->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	settings->disableFrameRate();
	hideCursor();
}

void MainProject::setup()
{
	camera = new MainCamera(Vec3f(0, 0, -1), Vec3f(0, 0, 0));

	const double ScaleX = 0xffff / GetSystemMetrics(SM_CXSCREEN);
	const double ScaleY = 0xffff / GetSystemMetrics(SM_CYSCREEN);

	INPUT input = {};
	input.type = INPUT_MOUSE;
	input.mi.dx = (LONG)(1000 * ScaleX);
	input.mi.dy = (LONG)(500 * ScaleY);
	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

	SendInput(1, &input, sizeof(INPUT));
	inc_pos = Vec2f(0, 0);
	material.setup(camera->getPos());
}

void MainProject::mouseMove( MouseEvent event )
{
	
	
	inc_pos = Vec2f(mouse_pos.x - event.getX(), mouse_pos.y - event.getY());
	
	if (mouse_pos != Vec2f(444, 416)) {
		camera->incliment_camera_angle(inc_pos);
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
void MainProject::mouseDrag(MouseEvent event)
{
	const double ScaleX = 0xffff / GetSystemMetrics(SM_CXSCREEN);
	const double ScaleY = 0xffff / GetSystemMetrics(SM_CYSCREEN);

	INPUT input = {};
	input.type = INPUT_MOUSE;
	input.mi.dx = (LONG)(1000 * ScaleX);
	input.mi.dy = (LONG)(500 * ScaleY);
	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

	SendInput(1, &input, sizeof(INPUT));

}

void MainProject::keyUp(KeyEvent event) {
	camera->pullKey(event);
}

void MainProject::keyDown(KeyEvent event) {
	camera->cameraMove(event);
}
void MainProject::update()
{
	
	material.update();
	camera->update();
}

void MainProject::draw()
{
	camera->draw();
	// clear out the window with black
	gl::clear( Color( 0.5, 0.5, 0.5 ) ); 
	
	material.draw();
}

CINDER_APP_NATIVE( MainProject, RendererGl )

