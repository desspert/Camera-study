#include "Key.h"



void KeyManager::insertPress(int pressed_key)
{
	press.insert(pressed_key);
}





void KeyManager::erasePressKey(int pressed_key)
{
	press.erase(press.find(pressed_key));
}

bool KeyManager::pressKey(int pressed_key) {
	if (press.find(pressed_key) != press.end()) {
		return true;
	}
	return false;
}


