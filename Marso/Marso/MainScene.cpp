#include "stdafx.h"
#include "MainScene.h"
#include"Stage1.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::OnEnter()
{
	BackGround = Sprite::Create(L"Resource/Main/BackGround.png");

	Score::Get()->S1->Alpha = 255;
	Score::Get()->S2->Alpha = 255;
	Score::Get()->S3->Alpha = 255;

	m_Anim = new Animation(1, 0);
	m_Anim->AddFrame(L"Resource/Main/Play.png");
	m_Anim->AddFrame(L"Resource/Main/Introduce.png");
	m_Anim->AddFrame(L"Resource/Main/Method.png");

	m_Anim->SetPos(800.f, 370.f);

	AddChild(BackGround);
	AddChild(m_Anim);
}

void MainScene::OnExit()
{
	//printf("MainScene OnExit\n");
}

void MainScene::Update()
{
	Scene::Update();

	switch (mainCount)
	{
	case 0:
		m_Anim->SetFrame(0);
		break;

	case 1:
		m_Anim->SetFrame(1);
		break;

	case 2:
		m_Anim->SetFrame(2);
		break;
	}

	if (Input::Get()->GetKeyState('W') == KeyState::Up)
	{
		mainCount--;

		if (mainCount < 0)
			mainCount = 0;

	}

	else if (Input::Get()->GetKeyState('S') == KeyState::Up)
	{
		mainCount++;

		if (mainCount > 2)
			mainCount = 2;

	}


	if(Input::Get()->GetKeyState(VK_RETURN) == KeyState::Up)
	{
		switch (mainCount)
		{
		case 0:
			Director::Get()->AlterScene(new Stage1());
			
			break;

		case 1:
			if (Introduce == nullptr)
				Introduce = Sprite::Create(L"Resource/Main/Introduce");
			else
			{
				Introduce->IsActive = 1;
				Method->IsActive = 0;
			}
			break;

		case 2:
			if (Method == nullptr)
				Method = Sprite::Create(L"Resource/Main/Method");
			else
			{
				Method->IsActive = 1;
				Introduce->IsActive = 0;
			}
			break;
		}
	}
}

void MainScene::Draw()
{
	Scene::Draw();
}
