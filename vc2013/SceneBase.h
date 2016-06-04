#pragma once


class SceneBase
{
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void setup() = 0;
	virtual void shift() = 0;
	
};