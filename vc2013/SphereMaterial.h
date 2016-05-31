#pragma once
#include "MaterialBase.h"

class SphereMaterial : public MaterialBase
{
private:
	int segments;
	float radius;
	Vec3f scale;
public:
	SphereMaterial(Vec3f _pos,Vec3f _size,Vec3f _translate, Vec3f _rotate,Vec3f _scale);
	void update() override;
	void draw() override;
};