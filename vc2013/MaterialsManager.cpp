#include "MaterialsManager.h"

MaterialManager::MaterialManager()
{
	
	
	
	
}

void MaterialManager::setup(Vec3f camera_pos) {
	sphere.push_back(std::make_shared <SphereMaterial>(Vec3f(0, 0, 0), Vec3f(1, 0.1, 1), Vec3f(0, 0, 0), Vec3f(0, 0, 0), Vec3f(1000, 1000, 1000)
		, "skydome", "Skydome151004y.jpg"));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, 0, 0), Vec3f(1, 1, 1), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "jimen", "ki.png"));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -2, 0), Vec3f(30, 1, 30), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "jimen", "ki.png"));
	/*cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -1.5, 0), Vec3f(10, 1, 10), Vec3f(0, 0, 0), Vec3f(0, 1, 0), "jimen", "ki.png"));*/
	//cube.push_back(std::make_shared<CubeMaterial>(camera_pos, Vec3f(1, 1, 1), Vec3f(0, 0, 5), Vec3f(0, 1, 0)));
	gl::enableDepthRead();
	gl::enableDepthWrite();
	gl::enable(GL_CULL_FACE);
}

void MaterialManager::update()
{
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
	for (auto it : cube) {
		it->draw();
	}
	for (auto it : sphere) {
		it->draw();
	}
	
}
