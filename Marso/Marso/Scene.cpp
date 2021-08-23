#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
	frame = 0;
	a = 0;
	b = 0;
	jin = 0;
	TotalFrame = 0;
	a = 10.f;
}

Scene::~Scene()
{
}

void Scene::JIN()
{
	jin = 1;

}
