#include "stdafx.h"
#include "Director.h"
#include"MainScene.h"
#include"Stage1.h"
#include"Stage2.h"


Director::Director()
	: m_CurrentScene(nullptr)
{
}

Director::~Director()
{
}

void Director::Update()
{
	if (m_CurrentScene)
		m_CurrentScene->Update();

	if (Input::Get()->GetKeyState(VK_ESCAPE) == KeyState::Up)
	{
		exit(0);
	}

	if (Input::Get()->GetKeyState(VK_F1) == KeyState::Up)
	{
		OurHero::Get()->Star = 1;
	} 

	if (Input::Get()->GetKeyState(VK_F2) == KeyState::Up)
	{
		OurHero::Get()->w += 1;
	}

	if (Input::Get()->GetKeyState(VK_F3) == KeyState::Up)
	{
		static int cccount;
		OurHero::Get()->AddOnPlayer(cccount+1);
		OurHero::Get()->AddOnCount++;
		cccount++;

		if (cccount > 4)
			cccount = 4;

	}

	if (Input::Get()->GetKeyState(VK_F4) == KeyState::Up)
	{
		Director::Get()->AlterScene(new MainScene());
	}

	if (Input::Get()->GetKeyState(VK_F5) == KeyState::Up)
	{
		Director::Get()->AlterScene(new Stage1());
	}

	if (Input::Get()->GetKeyState(VK_F6) == KeyState::Up)
	{
		Director::Get()->AlterScene(new Stage2());
	}
	
}

void Director::Draw()
{
	if (m_CurrentScene)
		m_CurrentScene->Draw();
}

void Director::AlterScene(Scene * scene)
{
	if (scene)
	{
		if (m_CurrentScene)
		{
			m_CurrentScene->OnExit();
			SAFE_DELETE(m_CurrentScene);
		}

		m_CurrentScene = scene;
		m_CurrentScene->OnEnter();
	}
}
