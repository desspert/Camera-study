#pragma once
#include "../src/ObjectBase.h"
#include "cinder/gl/Texture.h"
#include "cinder/imageIo.h"

class MaterialBase : public ObjectBase
{
protected:
	gl::Texture tx;
	Matrix44f matrix;
	Vec3f translate;
	Vec3f rotate;
public:
	MaterialBase(Vec3f _pos, Vec3f _size, Vec3f _translate, Vec3f _rotate) : ObjectBase(_pos, _size), 
		translate(_translate),
		rotate(_rotate){}
	virtual void update() {};
	virtual void draw() {};
	/*Matrix44f getMatrix() {
		return matrix;
	}*/

};