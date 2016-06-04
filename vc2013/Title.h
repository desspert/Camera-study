#pragma once
#include "CreateScene.h"
#include "Envent.h"

class Title : public SceneBase
{
public:
	Title();
	void setup() override;
	void update() override;
	void draw() override;
	void shift() override;
	
};