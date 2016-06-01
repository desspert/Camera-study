#pragma once
#include "MaterialBase.h"

class SphereMaterial : public MaterialBase
{
private:
	int segments;
	float radius;
	Vec3f scale;
	std::string name;
public:
	SphereMaterial(Vec3f _pos,Vec3f _size,Vec3f _translate, Vec3f _rotate,Vec3f _scale);
	SphereMaterial(Vec3f _pos, Vec3f _size, Vec3f _translate,
		Vec3f _rotate, Vec3f _scale,std::string name,std::string path);
	void update() override;
	void draw() override;
};