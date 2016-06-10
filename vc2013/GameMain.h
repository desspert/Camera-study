#pragma once
#include "MaterialsManager.h" 
#include "../src/MainCamera.h"
#include "Input.h"
#include "SceneBase.h"
#include "CreateScene.h"
#include "Collision.h"
#include "UIManager.h"
using namespace ci;
using namespace ci::app;

class GameMain : public SceneBase
{
private:
	MaterialManager material;
	UIManager ui;
	
public:
	GameMain();
	void setup() override;
	void update() override;
	void draw() override;
	void shift() override;
};