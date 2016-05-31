#include "MaterialsManager.h"

MaterialManager::MaterialManager()
{
	//sphere.push_back(std::make_shared <SphereMaterial>(Vec3f(0, 0, 0), Vec3f(1, 1000, 1000), Vec3f(0, 0, 0), Vec3f(0, 0, 0),Vec3f(100,100,100)));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, 0, 0), Vec3f(1, 1, 1), Vec3f(0, 0, 5), Vec3f(0, 1, 0)));
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -1.5, 0), Vec3f(10, 1, 10), Vec3f(0, 0, 0), Vec3f(0, 1, 0)));
	gl::enableDepthRead();
	gl::enableDepthWrite();
	gl::enable(GL_CULL_FACE);
}

void MaterialManager::update()
{
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
