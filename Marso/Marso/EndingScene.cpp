#include "stdafx.h"
#include "EndingScene.h"


EndingScene::EndingScene()
{
}


EndingScene::~EndingScene()
{
}

void EndingScene::OnEnter()
{
	Ending = Sprite::Create(L"Resource/BackGround/Ending.png");

	AddChild(Ending);
}

void EndingScene::OnExit()
{
}

void EndingScene::Update()
{
	Scene::Update();
}

void EndingScene::Draw()
{
	Scene::Draw();
}
