#pragma once
#include "CubeMaterial.h"
#include "SphereMaterial.h"
#include "../src/MainCamera.h"
#include "Collision.h"
#include <memory>
#include "cinder/Sphere.h"
#include "M4.h"

class MaterialManager {
private:
	std::vector<std::shared_ptr<MaterialBase>> player;
	std::vector<std::shared_ptr<MaterialBase>> cube;
	std::vector<std::shared_ptr<MaterialBase>> sphere;
	std::vector<std::shared_ptr<WeaponBase>> m4;
	std::shared_ptr<gl::Light> light;
public:
	MaterialManager();
	void update();
	void draw();
	void setup(Vec3f camera_pos);
};
