#pragma once
#include "MaterialBase.h"

class CubeMaterial : public MaterialBase
{
private:
	Vec3f translate;
	Vec3f rotate;
	Vec3f scale;
public:
	CubeMaterial(Vec3f _pos,Vec3f _size,Vec3f _translate,Vec3f _rotate);
	void update() override;
	void draw() override;

};