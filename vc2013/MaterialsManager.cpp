#include "MaterialsManager.h"

MaterialManager::MaterialManager()
{
	cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, 0, 3), Vec3f(1, 1, 1), Vec3f(1, 1, 0), Vec3f(10.3, 1.2, 0.5)));
	gl::enableDepthRead();
	gl::enableDepthWrite();
	gl::enable(GL_CULL_FACE);
}

void MaterialManager::update()
{
}

void MaterialManager::draw()
{
	for (auto it : cube) {
		it->draw();
	}
	
	
}
