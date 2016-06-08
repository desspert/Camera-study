#pragma once
#include "WeaponBase.h"

class M4  : public WeaponBase
{
private:
	Vec3f scale;
	std::string name;
public:
	M4(Vec3f _pos, Vec3f _size, Vec3f _translate, Vec3f _rotate,Vec3f _scale, std::string name, std::string path)
		:WeaponBase(_pos, _size, _translate,_rotate) , scale(_scale)
	{
		TEX.set(name, path);
		this->name = name;
	}
	void setup();
	void update() override;
	void draw() override;
	void fire() override;
};