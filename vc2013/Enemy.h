#pragma once

#include "../src/ObjectBase.h"
#include "../src/MainCamera.h"
class Enemy : public ObjectBase
{
private:
	int hp;
	int attack;
	bool insert;
	bool arrive;
public:
	Enemy(Vec3f _pos, Vec3f _size);
	void update();
	void draw();
	void setInsert(bool set) {
		insert = set;
	}
	bool getInsert() {
		return insert;
	}
	void damage(int damage) {
		hp -= damage;
	}
	bool getArrive() {
		return arrive;
	}
};