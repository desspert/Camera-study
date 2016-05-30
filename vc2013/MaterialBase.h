#pragma once
#include "../src/ObjectBase.h"
#include "cinder/gl/Texture.h"
#include "cinder/imageIo.h"

class MaterialBase : public ObjectBase
{
protected:
	gl::Texture tx;
	Matrix44f matrix;
public:
	MaterialBase(Vec3f _pos, Vec3f _size) : ObjectBase(_pos, _size) {}
	virtual void update() {};
	virtual void draw() {};
	/*Matrix44f getMatrix() {
		return matrix;
	}*/

};