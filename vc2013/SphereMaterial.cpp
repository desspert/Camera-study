#include "SphereMaterial.h"

SphereMaterial::SphereMaterial(Vec3f _pos, Vec3f _size, Vec3f _translate, Vec3f _rotate, Vec3f _scale)
 : MaterialBase(_pos,_size,_translate,_rotate)
{
	radius = 0.5f;
	segments = 12;
	scale = _scale;
}

void SphereMaterial::update()
{
}

void SphereMaterial::draw()
{
	gl::pushModelView();
	gl::translate(translate);
	gl::rotate(rotate);
	gl::scale(scale);
	gl::drawSphere(pos,radius,segments);
	gl::popModelView();
}
