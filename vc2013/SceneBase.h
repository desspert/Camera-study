#pragma once

class SceneBase {
public:
	virtual void title() = 0;
	virtual void gameMain() = 0;
	virtual void result() = 0;
};