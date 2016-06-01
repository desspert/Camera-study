#include "SphereMaterial.h"

SphereMaterial::SphereMaterial(Vec3f _pos, Vec3f _size, Vec3f _translate, Vec3f _rotate, Vec3f _scale)
 : MaterialBase(_pos,_size,_translate,_rotate)
{
	radius = 0.5f;
	segments = 12;
	scale = _scale;
}

SphereMaterial::SphereMaterial(Vec3f _pos, Vec3f _size,
	Vec3f _translate, Vec3f _rotate, Vec3f _scale,
	std::string name,std::string path
	)
	: MaterialBase(_pos, _size, _translate, _rotate)
{
	radius = 0.5f;
	segments = 30;
	scale = _scale;
	TEX.set(name, path);
	this->name = name;
	
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

	TEX.get(name).enableAndBind();
	glCullFace(GL_FRONT);
	gl::drawSphere(pos,radius,segments);
	glCullFace(GL_BACK);
	TEX.get(name).disable();
	gl::popModelView();
}
