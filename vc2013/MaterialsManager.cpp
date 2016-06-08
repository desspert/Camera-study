#include "MaterialsManager.h"

MaterialManager::MaterialManager()
{
	
	
	
	
}

void MaterialManager::setup(Vec3f camera_pos) {
	light = std::make_shared<gl::Light>(gl::Light::DIRECTIONAL, 0);

	light->setAmbient(Color(1.0f, 1.0f, 1.0f));
	light->setDiffuse(Color(0.8f, 0.8f, 0.8f));
	light->setSpecular(Color(0.5f, 0.5f, 0.5f));
	light->setDirection(Vec3f(0.0f, 1.0f, -1.0f));

	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
	
	sphere.push_back(std::make_shared <SphereMaterial>(Vec3f(0, 0, 0), Vec3f(1, 0.1, 1), Vec3f(0, 0, 0), Vec3f(0, 0, 0), Vec3f(1000, 1000, 1000)
		, "skydome", "Skydome151004y.jpg"));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, 0, 0), Vec3f(1, 1, 1), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "kabe", "ki.png"));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -2, 0), Vec3f(50, 1, 50), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "jimen", "1762.jpg"));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(20, -5, 0), Vec3f(10, 30, 40), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "bill","img_9.jpg"));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(-20, -5, 0), Vec3f(10, 30, 40), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "bill", "img_9.jpg"));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -5, 20), Vec3f(40, 30, 10), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "bill", "img_9.jpg"));
	/*cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -1.5, 0), Vec3f(10, 1, 10), Vec3f(0, 0, 0), Vec3f(0, 1, 0), "jimen", "ki.png"));*/
	//cube.push_back(std::make_shared<CubeMaterial>(camera_pos, Vec3f(1, 1, 1), Vec3f(0, 0, 5), Vec3f(0, 1, 0)));
	gl::enableDepthRead();
	gl::enableDepthWrite();
	gl::enable(GL_CULL_FACE);
	for (auto it : cube) {
		it->setup();
	}
	m4.push_back(std::make_shared<M4>(Vec3f(5,0,0),Vec3f(0, 0, 0),Vec3f(0,1,0),Vec3f(1,1,0),Vec3f(0.004,0.004,0.004),"ak", "cfn_01_b.jpg"));
	for (auto it : m4) {
		it->setup();
	}
}

void MaterialManager::update()
{
	for (auto it : m4) {
		it->setPos(CAMERA.getPos());
		it->update();
		it->fire();
	}
	CAMERA.getRay().setOrigin(CAMERA.getPos() + Vec3f(0,1,0));
	CAMERA.getRay().setDirection(CAMERA.getInsertPoint() * (1000,1000,1000) + Vec3f(0, 1, 0));
	
	CAMERA.setPos(Vec3f(CAMERA.getPos().x, CAMERA.getPos().y - 0.01, CAMERA.getPos().z));
	for (auto it : cube) {
		CAMERA.setPos(returnBoxToBox(CAMERA.getPos(), CAMERA.getSize(), it->getPos(), it->getSize()));
	}
	for (auto it : cube) {
		it->update();
		
	}
	for (auto it : sphere) {
		it->update();
	}
	
	
}

void MaterialManager::draw()
{
	gl::color(1, 1, 1);
	gl::enable(GL_LIGHTING);
	gl::enable(GL_NORMALIZE);
	
	light->enable();
	float t[2];
	t[0] = 0;
	
	
	
	for (auto it : cube) {
		it->draw();
		it->box->intersect(CAMERA.getRay(), &t[0]);
	}
	for (auto it : sphere) {
		it->draw();
	}
	
	if (t[0] > 0 ) {
		
	}
	else {
		
	}
	gl::color(0, 1, 0);
	for (auto it : cube) {
		gl::drawStrokedCube(it->box->getMin() + it->box->getSize() / 2, it->box->getSize());
		console() << it->box->getMin() << std::endl;
		console() << it->box->getMax() << std::endl;
	}
	gl::color(1, 0, 0);
	gl::drawVector(CAMERA.getRay().getOrigin(), CAMERA.getRay().getOrigin() + CAMERA.getRay().getDirection());
	
	gl::pushModelView();
	gl::color(0, 0, 1);
	gl::drawSphere(CAMERA.getRay().calcPosition(t[0]), 0.1f, 12);
	gl::popModelView();
	for (auto it : m4) {
		it->draw();
	}
}
