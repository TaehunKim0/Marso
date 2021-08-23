#include "stdafx.h"
#include "Effect.h"


Effect::Effect()
{
}

Effect::~Effect()
{
}

void Effect::Init(float x, float y, EffectType type , float angle)
{
	switch (type)
	{
	case EffectType::BulletCollide:
		m_Effect = Sprite::Create(L"Resource/Effect/Bullet.png");
		m_Type = type;
		break;

	case EffectType::EnemyDead:
		m_Effect = Sprite::Create(L"Resource/Effect/Died.png");
		m_Type = type;
		break;
	}

	m_Angle = angle;
	frame = 0;
	SetPos(x, y);
	AddChild(m_Effect);
}

void Effect::Update()
{
	Node::Update();

	if (m_Type == EffectType::BulletCollide)
	{
		Translate(cos(m_Angle) * 5.f, sin(m_Angle)* 5.f);
	}

	frame++;

	if (frame >= 10)
	{
		Destroy();
		this->IsActive = 0;
	}
}

void Effect::Draw()
{
	Node::Draw();
}
