#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"        // ライティング
#include "cinder/gl/Material.h"     // マテリアル(材質)
#include "cinder/Camera.h"
#include "ObjectBase.h"
#include "MainCamera.h"
#include "../../Camera-study/vc2013/MaterialsManager.h"

class MainProject : public AppNative {
private:
	MainCamera* camera;
	MaterialManager material;
	
  public:
	  

	void prepareSettings(Settings* settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void MainProject::prepareSettings(Settings* settings) {
	settings->setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	settings->disableFrameRate();
}

void MainProject::setup()
{
	camera = new MainCamera(Vec3f(0, 0, -1), Vec3f(0, 0, 0));
	
}

void MainProject::mouseDown( MouseEvent event )
{
}

void MainProject::update()
{
}

void MainProject::draw()
{
	camera->draw();
	// clear out the window with black
	gl::clear( Color( 0.5, 0.5, 0.5 ) ); 
	
	material.draw();
}

CINDER_APP_NATIVE( MainProject, RendererGl )
