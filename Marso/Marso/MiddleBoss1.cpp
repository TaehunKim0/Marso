#include "stdafx.h"
#include "MiddleBoss1.h"


MiddleBoss1::MiddleBoss1()
{
	Attacking = 0;
	a = 0;
}

MiddleBoss1::~MiddleBoss1()
{
	ObjectPool::Get()->CreateItem(m_Pos.x + GetCenter().x, m_Pos.y + GetCenter().y, ItemGroup::WeaponUp);
}

void MiddleBoss1::Init(Vector2 pos, Tag tag)
{
	ImBoss = 1;
	m_Anim = new Animation(10, 1);
	m_Anim->AddFrame(L"Resource/Enemy/MiddleBoss1.png");
	m_Anim->AddFrame(L"Resource/Enemy/MiddleBoss2.png");

	SetPos(pos.x, pos.y);
	m_Tag = tag;

	m_Direction = Direction::Left;
	Unit::Init(pos.x, pos.y, tag, L"MiddleBoss1", 100);
	AddChild(m_Anim);
}

void MiddleBoss1::Update()
{
	Unit::Update();

	switch (m_Direction)
	{
	case Direction::Left:
		Translate(-1.f, 0.f);
		break;

	case Direction::Right:
		Translate(1.f, 0.f);
		break;
	}

	Frame2++;

	if (Frame2 >= 230)
	{
		if (m_Direction == Direction::Right)
			m_Direction = Direction::Left;

		else
			m_Direction = Direction::Right;
		
		Frame2 = 0;
	}

	if(Attacking == 0)
		Frame1++;

	if(Attacking == 0)
		if (Frame1 >= 120)
		{
			//Attacking = 1;
			Frame1 = 0;
		}

	if (Attacking)
		Attack();

}

void MiddleBoss1::Draw()
{
	Unit::Draw();
}

void MiddleBoss1::CollideWith(Node * other)
{
	Unit::CollideWith(other);
}

void MiddleBoss1::Attack()
{
	ObjectPool::Get()->FireBullet(m_Pos + GetCenter() - Vector2(100.f,0.f), Tag::Enemy, Direction::None, 7.f, L"Resource/Bullet/Player2.png", D3DXToRadian(a));
	
	a += 22;

	if (a >= 360)
	{
		Attacking = 0;
		a = 0;
	}
}