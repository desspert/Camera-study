#pragma once
#include "Collision.h"
#include <memory>
#include "MaterialBase.h"
#include "Plate.h"
#include "AK.h"
class UIManager
{
private:
	std::vector<std::shared_ptr<UIPlate>> plate;
	bool trigger;
public:
	void setup();
	void update();
	void draw();
	void setTrigger(bool set) {
		trigger = set;
	}
};