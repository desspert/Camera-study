#include "CubeMaterial.h"

CubeMaterial::CubeMaterial(Vec3f _pos, Vec3f _size,Vec3f _translate,Vec3f _rotate)
	: MaterialBase(_pos, _size,_translate,_rotate) {
	
	angle = 0.0f;
}

void CubeMaterial::update()
{
	
	
	
}

void CubeMaterial::draw()
{
	gl::pushModelView();
	gl::translate(translate);
	gl::rotate(rotate);
	gl::drawCube(pos, size);
	gl::popModelView();
}

