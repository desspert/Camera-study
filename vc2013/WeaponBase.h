#pragma once

#include "../src/MainCamera.h"
#include "MaterialBase.h"
#include "Input.h"
#include "cinder/imageIo.h"
#include "cinder/ObjLoader.h"       
#include "cinder/TriMesh.h"  
#include "SoundManager.h"



class WeaponBase : public MaterialBase
{
protected:
	TriMesh mesh;
	
	int attack_point;
	int rate;
	int bullets;
	//ƒTƒu’e–ò
	int reserve;
	float scatter;
	bool trigger;
public:
	
	WeaponBase(Vec3f _pos, Vec3f _size, Vec3f _translate, Vec3f _rotate)
		: MaterialBase(_pos, _size, _translate, _rotate) {}
	void update() {};
	void draw() {};
	virtual void  fire() = 0;
	int getAttackPoint() {
		return attack_point;
	}
	bool getTrigger() {
		return trigger;
	}
};
