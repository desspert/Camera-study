#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "../vc2013/SceneManager.h"
#include "../vc2013/CreateScene.h"
#include "../src/MainCamera.h"
#include "../vc2013/INPUT.h"
#include "../vc2013/MaterialsManager.h"

class MainProject : public AppNative {
private:
	SceneManager scene;
 public:
	void prepareSettings(Settings* settings);
	void setup();
	void mouseMove(MouseEvent event) override;
	void mouseDrag(MouseEvent event) override;
	void update();
	void keyDown(KeyEvent event) override;
	void keyUp(KeyEvent event) override;
	void draw();
	void shift();
};

void MainProject::prepareSettings(Settings* settings) {
	
	settings->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	settings->disableFrameRate();
	hideCursor();
}

void MainProject::setup()
{
	scene.setup();
	
}

void MainProject::mouseMove(MouseEvent event)
{

	ENV.mouseMove(event);


}
void MainProject::mouseDrag(MouseEvent event)
{

	ENV.mouseDrag(event);

}

void MainProject::keyUp(KeyEvent event) {

	ENV.keyUp(event);
}

void MainProject::keyDown(KeyEvent event) {

	ENV.keyDown(event);
}
void MainProject::update()
{

	scene.update();
}

void MainProject::draw()
{

	gl::clear(Color(0.5, 0.5, 0.5));
	scene.draw();

}

void MainProject::shift()
{
	scene.shift();
}


CINDER_APP_NATIVE( MainProject, RendererGl )

