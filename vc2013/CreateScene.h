#pragma once
#include <memory>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneBase.h"
using namespace ci;
using namespace ci::app;
class Scene
{
public:
	template<typename ty>
	static void create(ty* _scene) {
		scene = std::make_shared<ty>(*_scene);
	};
	
	static SceneBase& get() {
		return *scene;
	}
	
private:
	static std::shared_ptr<SceneBase> scene;
}; 
