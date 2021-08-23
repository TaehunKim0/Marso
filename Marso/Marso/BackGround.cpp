#include "stdafx.h"
#include "BackGround.h"
#include "Meteor.h"

BackGround::BackGround()
{
	sFrame = 0; ssFrame = 0; Meteored = 0;
}

BackGround::~BackGround()
{
}

//177

void BackGround::Init(int stage)
{
	switch (stage)
	{
	case 1:
		back1 = Sprite::Create(L"Resource/BackGround/Stage1.png");
		back2 = Sprite::Create(L"Resource/BackGround/Stage1.png");

		back1->SetPos(0.f, -2710 + 720);
		back2->SetPos(0.f, -2710 + 720);

		AddChild(back1);
		AddChild(back2);

		//AddChild(Light1);

		break;

	case 2:
		back1 = Sprite::Create(L"Resource/BackGround/Stage2.png");
		back2 = Sprite::Create(L"Resource/BackGround/Stage2.png");

		back1->SetPos(0.f, -2710 + 720);
		back2->SetPos(0.f, -2710 + 720);

		AddChild(back1);
		AddChild(back2);

		break;
	}

	Mark = Sprite::Create(L"Resource/BackGround/Mark.png");
	Jull = Sprite::Create(L"Resource/BackGround/Jull.png");

	Mark->SetPos(101001, 100101);
	Mark->m_Scale = Mark->m_Scale / 2;

	Jull->SetPos(101010, 100101);

	AddChild(Mark);
	AddChild(Jull);
}

void BackGround::Update()
{
	Node::Update();

	sFrame++;

	if (Meteored == 0)
		if (sFrame >= 60 * 8)
		{
			Meteored = 1;
			randomX = OurHero::Get()->m_Pos.x;
		}

	if (Meteored)
	{
		FireMetor(randomX, -100);
	}

	back1->Translate(0.f, 5.f);
	back2->Translate(0.f, 5.f);

	if (back1->m_Pos.y >= 0)
		back2->SetPos(0.f, back1->m_Pos.y - back1->m_Size.y);

	if (back2->m_Pos.y >= 0)
		back1->SetPos(0.f, back2->m_Pos.y - back2->m_Size.y);
	
}

void BackGround::Draw()
{
	Node::Draw();
}

void BackGround::FireMetor(int x, int y)
{
	ssFrame++;

	if (ssFrame <= 120)
	{
		Mark->SetPos(randomX, y + 100);
		Jull->SetPos(randomX + 30.f, Mark->m_Pos.y + 65.f);
	}
	else
	{
		Mark->SetPos(x - 10000, y + 120);
		Jull->SetPos(x - 10000, 0.f);

		auto meto = new Meteor();
		meto->Init(randomX - 50.f, -100.f);
		AddChild(meto);
		sFrame = 0;
		Meteored = 0;
		ssFrame = 0;

	}
	
}

///////////////////////////////////////




