#pragma once
#include "../src/ObjectBase.h"
#include "cinder/gl/Texture.h"
#include "cinder/imageIo.h"
#include "cinder/gl/Material.h"
class MaterialBase : public ObjectBase
{
protected:
	gl::Texture tx;
	Matrix44f matrix;
	Matrix44f matrix_t;
	Matrix44f matrix_r;
	Vec3f translate;
	Vec3f rotate;
	gl::Material material;
public:
	MaterialBase(Vec3f _pos, Vec3f _size, Vec3f _translate, Vec3f _rotate) : ObjectBase(_pos, _size), 
		translate(_translate),
		rotate(_rotate){}
	virtual void update() {};
	virtual void draw() {};
	void damage(int damage) {};
	/*Matrix44f getMatrix() {
		return matrix;
	}*/

};