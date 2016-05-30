#pragma once
#include "CubeMaterial.h"
#include <memory>
class MaterialManager {
private:
	std::list<std::shared_ptr<MaterialBase>> cube;
public:
	MaterialManager();
	void update();
	void draw();
};
