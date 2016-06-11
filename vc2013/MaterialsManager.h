#pragma once
#include "CubeMaterial.h"
#include "SphereMaterial.h"
#include "../src/MainCamera.h"
#include "Collision.h"
#include <memory>
#include "cinder/Sphere.h"
#include "AK.h"
#include "Enemy.h"

class MaterialManager {
private:
	std::vector<std::shared_ptr<MaterialBase>> player;
	std::list<std::shared_ptr<ObjectBase>> object;
	std::vector<std::shared_ptr<MaterialBase>> sphere;
	std::vector<std::shared_ptr<WeaponBase>> ak;
	std::shared_ptr<gl::Light> light;
	
	float t[2];
	bool trigger;
	Vec3f ray_pos;
public:
	MaterialManager();
	bool getTrigger() {
		return trigger;
	}
	void update();
	void draw();
	void setup(Vec3f camera_pos);
};
