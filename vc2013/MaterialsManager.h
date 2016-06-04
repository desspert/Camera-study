#pragma once
#include "CubeMaterial.h"
#include "SphereMaterial.h"
#include "../src/MainCamera.h"
#include "Collision.h"
#include <memory>
class MaterialManager {
private:
	std::vector<std::shared_ptr<MaterialBase>> player;
	std::vector<std::shared_ptr<MaterialBase>> cube;
	std::list<std::shared_ptr<MaterialBase>> sphere;
public:
	MaterialManager();
	void update();
	void draw();
	void setup(Vec3f camera_pos);
};
