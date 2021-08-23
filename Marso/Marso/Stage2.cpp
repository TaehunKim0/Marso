#include "stdafx.h"
#include "Stage2.h"
#include"Stage1.h"
#include"BackGround.h"
#include"MiddleBoss2.h"
#include"LastBoss2.h"
#include"EndingScene.h"
#include"MainScene.h"

Stage2::Stage2()
{
	frame1 = 0;
	frame2 = 0;
	frame3 = 0;
	f = 0;
	ff = 0;
	yes = 1;
	aaa = 0;
	bbb = 0;
	a = 0;

	OurHero::Get()->w += 1;
	OurHero::Get()->AddOnCount = 0;

	middleBossed = 0;
	lastBossed = 0;
	spawn = 1;
}

Stage2::~Stage2()
{
}

void Stage2::OnEnter()
{
	("Stage2 OnEnter\n");

	Player = OurHero::Get();
	Player->Init(500, 500);

	backGround = new BackGround();
	backGround->Init(2);
	score = Score::Get();

	progress = new Progress();
	progress->Init(1190.f, 620.f);

	ObjectPool::Get()->Init(this);

	AddChild(backGround);
	AddChild(progress);
}

void Stage2::OnExit()
{
	("Stage2 OnExit\n");

	ObjectPool::Get()->Release();
	ObjectPool::Get()->Release();
	OurHero::Get()->Release();

	Player->Died = 0;
}

void Stage2::Update()
{
	Scene::Update();

	Player->Update();
	score->Update();

	if (spawn)
		SpawnEnemys();

	//보스 소환
	if (middleBossed == 0)
		if (aaa == 0)
			if (progress->middle)
			{
				SpawnMiddle(300, -100.f);
				frame2 = 0;
				middleBossed = 1;
				progress->SetGo(0);
				spawn = 0;
				aaa = 1;
			}

	if (lastBossed == 0)
		if (bbb == 0)
			if (progress->last)
			{
				SpawnLast(100, -100.f);
				frame2 = 0;
				lastBossed = 1;
				progress->SetGo(0);
				spawn = 0;
				bbb = 1;
			}

	//중간보스 등장시
	if (middleBossed)
	{
		frame2++;
		if (frame2 >= 360)
		{
			int random = (rand() % 1230) + 50;
			ObjectPool::Get()->SpawnStraight(random, -100);
			frame2 = 0;
		}
	}
	//마지막 보스 등장시
	if (lastBossed)
	{
		frame2++;
		if (frame2 >= 360)
		{
			int random = (rand() % 1230) + 50;
			//ObjectPool::Get()->SpawnStraight(random, -100);
			frame2 = 0;
		}
	}

	//보스 죽는 것 체크
	if(middleBossed)
		if (middle)
			if (middle->tag < 0)
			{
				middleBossed = 0;
				progress->SetGo(1);
				spawn = 1;
			}



	if (Input::Get()->GetKeyState(VK_UP) == KeyState::Up)
		Player->Died = 1;

	if (Player->Died)
	{
		spawn = 0;

		score->S1->Alpha = 100;
		score->S2->Alpha = 100;
		score->S3->Alpha = 100;

		if (f == 0)
		{
			Black = Sprite::Create(L"Resource/BackGround/Black.png");
			GameOver = Sprite::Create(L"Resource/BackGround/GameOver.png");
			GameOver->SetPos(270.f, 800.f);

			AddChild(Black);
			AddChild(GameOver);
			f = 1;
		}

		ff++;

		if (ff <= 270)
		{
			GameOver->Translate(0.f, -2.f);
			("GameOver : %f\n", GameOver->m_Pos.y);
		}

		else
		{
			GameOver->Alpha = 0;

			if (a == false)
			{
				RetryButton = new Animation(1, 0);
				RetryButton->AddFrame(L"Resource/BackGround/No.png");
				RetryButton->AddFrame(L"Resource/BackGround/Yes.png");

				RetryButton->SetPos(270.f, 420.f);

				Retry = Sprite::Create(L"Resource/BackGround/Retry.png");
				Retry->SetPos(350.f, 270.f);

				AddChild(RetryButton);
				AddChild(Retry);
				yes = 1;
				a = 1;
			}

			if (Input::Get()->GetKeyState('A') == KeyState::Up)
			{
				RetryButton->SetFrame(0);
				yes = 1;
			}

			else if (Input::Get()->GetKeyState('D') == KeyState::Up)
			{
				RetryButton->SetFrame(1);
				yes = 0;
			}

			if (Input::Get()->GetKeyState(VK_RETURN) == KeyState::Up)
			{
				switch (yes)
				{
				case 0:
					exit(0);
					break;

				case 1:
					Director::Get()->AlterScene(new MainScene());
					return;
					break;
				}
			}
		}
	}

	if (lastBossed)
		if (last)
			if (last->tag < 0)
			{
				lastBossed = 0;
				Director::Get()->AlterScene(new EndingScene());
			}

}

void Stage2::Draw()
{
	Scene::Draw();

	Player->Draw();
	score->Draw();
}

void Stage2::SpawnMiddle(int x, int y)
{
	middle = new MiddleBoss2();
	middle->Init(Vector2(x, y), Tag::Enemy);

	ObjectPool::Get()->m_Enemys.push_back(middle);

	AddChild(middle);
}

void Stage2::SpawnLast(int x, int y)
{
	last = new LastBoss2();
	last->Init(Vector2(x, y), Tag::Enemy);

	ObjectPool::Get()->m_Enemys.push_back(last);

	AddChild(last);
}

void Stage2::SpawnEnemys()
{
	frame1++;
	frame2++;
	frame3++;

	if (frame1 >= 400)
	{
		int randomxx = (rand() % 2)+1;

		if (randomxx == 1)
		{
			int random = (rand() % 1230) + 50;
			ObjectPool::Get()->SpawnDivide(random, -100);
		}

		else if(randomxx == 2)
		{
			int random = (rand() % 800) + 50;
			ObjectPool::Get()->SpawnFlightFormation(random, -100);
		}

		frame1 = 0;
	}

	if (frame3 >= 240)
	{
		int random = (rand() % 1230) + 50;
		ObjectPool::Get()->SpawnStraight(random, -100);
		frame3 = 0;
	}

}
