#include "CubeMaterial.h"

CubeMaterial::CubeMaterial(Vec3f _pos, Vec3f _size,Vec3f _translate,Vec3f _rotate)
	: MaterialBase(_pos, _size) {
	translate = _translate;
	rotate = _rotate;
	scale = Vec3f(1, 1, 1);
}

void CubeMaterial::update()
{
	
}

void CubeMaterial::draw()
{
	gl::pushModelView();
	gl::translate(translate);
	gl::rotate(rotate);
	gl::drawColorCube(pos, size);
	gl::popModelView();
}

