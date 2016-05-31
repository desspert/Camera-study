#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"        // ライティング
#include "cinder/gl/Material.h"     // マテリアル(材質)
#include <iostream>
#include <set>
using namespace ci;
using namespace ci::app;
using namespace std;
#define KEY KeyManager::get()
class KeyManager : public AppNative
{
private:
	std::set<int> press;
	std::set<int> push;
	std::set<int> pull;
public:
	KeyManager() {};
	
	void insertPush(int pressed_key);
	void insertPress(int pressed_key);
	void insertPull(int pressed_key);

	void erasePressKey(int pressed_key);
	
	bool pressKey(int pressed_key);
	bool pushKey();
	bool isPull();

	static KeyManager &get() {
		static KeyManager key;
		return key;
	}
};