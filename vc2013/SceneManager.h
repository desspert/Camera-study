#pragma once
#include "SceneBase.h"

class SceneManager : public SceneBase
{
private:

public:
	void title() override;
	void gameMain() override;
	void result() override;
};