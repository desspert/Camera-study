#pragma once
#include "MaterialBase.h"

class CubeMaterial : public MaterialBase
{
private:
	
	std::string name;
	float angle;
public:
	CubeMaterial(Vec3f _pos, Vec3f _size, Vec3f _translate, Vec3f _rotate
		, std::string name, std::string path);
	void update() override;
	void draw() override;
	void setup();
};