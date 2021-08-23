#include "stdafx.h"
#include "Animation.h"


Animation::Animation()
	: CurrentFrame(0)
	, Delay(0)
	, AutoPlay(1)
	, FrameCounter(0)
	, IsAnimEnd(0)
	, tick(0)
	, Alpha(255)
	, died(0)
{

}

Animation::Animation(int delay, bool _auto)
{
	Delay = delay;
	AutoPlay = _auto;
	this->Alpha = 255;
}

Animation::~Animation()
{
}

void Animation::AddFrame(std::wstring fileName)
{
	auto sprite = Sprite::Create(fileName);
	sprite->m_Parent = this;
	m_Size = sprite->m_Size;

	m_Anim.push_back(sprite);
}

void Animation::Update()
{
	Node::Update();

	FrameCounter++;

	if(AutoPlay)
		if (FrameCounter > Delay)
		{
			CurrentFrame++;
			FrameCounter = 0;
		}

	if (CurrentFrame >= m_Anim.size())
	{
		CurrentFrame = 0;
		IsAnimEnd = 1;
	}

	m_Anim.at(CurrentFrame)->Update();
}

void Animation::Draw()
{
	Node::Draw();

	if (tick)
	{
		m_Anim.at(CurrentFrame)->Tick();
		tick = 0;
	}
	if (died)
	{
		m_Anim.at(CurrentFrame)->Died();
		died = 0;
	}
	m_Anim.at(CurrentFrame)->Draw();
}
