#include "stdafx.h"
#include "Score.h"


Score::Score()
{
	S1Count = 0;
	S2Count = 0;
	S3Count = 0;

	score = 0;

	S1 = new Animation(1, 0);
	S2 = new Animation(1, 0);
	S3 = new Animation(1, 0);

	for (int i = 0; i < 10; i++)
		S1->AddFrame(L"Resource/UI/Font/" + std::to_wstring(i) + L".png");

	for (int j = 0; j < 10; j++)
		S2->AddFrame(L"Resource/UI/Font/" + std::to_wstring(j) + L".png");

	for (int p = 0; p < 10; p++)
		S3->AddFrame(L"Resource/UI/Font/" + std::to_wstring(p) + L".png");

	S3->Translate(1120.f, 30.f);
	S2->Translate(1170.f, 30.f);
	S1->Translate(1220.f, 30.f);

	AddChild(S1);
	AddChild(S2);
	AddChild(S3);
	
}

Score::~Score()
{
}

void Score::Update()
{
	Node::Update();

	switch (S1Count)
	{
	case 0:
		S1->SetFrame(0);
		break;

	case 1:
		S1->SetFrame(1);
		break;

	case 2:
		S1->SetFrame(2);
		break;

	case 3:
		S1->SetFrame(3);
		break;

	case 4:
		S1->SetFrame(4);
		break;

	case 5:
		S1->SetFrame(5);
		break;

	case 6:
		S1->SetFrame(6);
		break;

	case 7:
		S1->SetFrame(7);
		break;

	case 8:
		S1->SetFrame(8);
		break;

	case 9:
		S2->SetFrame(9);
		break;

	}

	switch (S2Count)
	{
	case 0:
		S2->SetFrame(0);

		break;
	case 1:
		S2->SetFrame(1);
		break;

	case 2:
		S2->SetFrame(2);
		break;

	case 3:
		S2->SetFrame(3);
		break;

	case 4:
		S2->SetFrame(4);
		break;

	case 5:
		S2->SetFrame(5);
		break;

	case 6:
		S2->SetFrame(6);
		break;

	case 7:
		S2->SetFrame(7);
		break;

	case 8:
		S2->SetFrame(8);
		break;

	case 9:
		S2->SetFrame(9);
		break;
	case 10:
		S2->SetFrame(0);
		break;
	}

	switch (S3Count)
	{
	case 0:
		S3->SetFrame(0);
		break;
	case 1:
		S3->SetFrame(1);
		break;

	case 2:
		S3->SetFrame(2);
		break;

	case 3:
		S3->SetFrame(3);
		break;

	case 4:
		S3->SetFrame(4);
		break;

	case 5:
		S3->SetFrame(5);
		break;

	case 6:
		S3->SetFrame(6);
		break;

	case 7:
		S3->SetFrame(7);
		break;

	case 8:
		S3->SetFrame(8);
		break;

	case 9:
		S3->SetFrame(9);
		break;
	}


}


void Score::Draw()
{
	Node::Draw();
}

void Score::Calc()
{
	S1Count = score % 10;

	if (S2Count > 10)
		S2Count = (score / 10) % 10;

	else
		S2Count = score / 10;

	S3Count = score / 100;
}
