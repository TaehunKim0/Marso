#include "stdafx.h"
#include "Progress.h"


Progress::Progress()
{
	ProgressGo = 1;
	middle = 0;
	last = 0;
}

Progress::~Progress()
{
}

void Progress::Init(float x, float y)
{
	SetPos(x, y);

	progress = Sprite::Create(L"Resource/UI/Progress.png");

	AddChild(progress);
}

void Progress::Update()
{
	Node::Update();

	if(ProgressGo)
		Translate(0.f, -0.1f);

		if (m_Pos.y <= 410)
			middle = 1;

		if (m_Pos.y <= 180)
			last = 1;
}

void Progress::Draw()
{
	Node::Draw();
}

void Progress::StartWeb()
{
}
