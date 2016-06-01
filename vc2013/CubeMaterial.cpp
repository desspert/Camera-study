#include "CubeMaterial.h"

CubeMaterial::CubeMaterial(Vec3f _pos, Vec3f _size,Vec3f _translate,Vec3f _rotate,
	std::string name, std::string path)
	: MaterialBase(_pos, _size,_translate,_rotate) {
	TEX.set(name, path);
	this->name = name;
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

	TEX.get(name).enableAndBind();

	gl::drawCube(pos, size);

	TEX.get(name).disable();
	gl::popModelView();
}

