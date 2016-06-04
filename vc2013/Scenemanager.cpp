#include "SceneManager.h"

SceneManager::SceneManager()
{
	Scene::create<GameMain>(new GameMain());
}


void SceneManager::setup()
{
	Scene::get().setup();
}

void SceneManager::update()
{
	Scene::get().update();
}

void SceneManager::draw()
{
	Scene::get().draw();
}


void SceneManager::shift()
{
	Scene::get().shift();
}

