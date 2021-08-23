#include "stdafx.h"
#include "LastBoss2.h"


LastBoss2::LastBoss2()
{
	Attacking = 0;
}


LastBoss2::~LastBoss2()
{
}

void LastBoss2::Init(Vector2 pos, Tag tag)
{
	ImBoss = 1;
	m_Anim = new Animation(1, 0);
	m_Anim->AddFrame(L"Resource/Enemy/LastBoss2.png");

	SetPos(pos.x, pos.y);
	m_Tag = tag;

	m_Direction = Direction::Left;



	Unit::Init(pos.x, pos.y, tag, L"LastBoss2", 500);

	AddChild(m_Anim);
}

void LastBoss2::Update()
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

	Frame3++;

	if (Frame3 >= 230)
	{
		if (m_Direction == Direction::Right)
			m_Direction = Direction::Left;

		else
			m_Direction = Direction::Right;

		Frame3 = 0;
	}

	Frame2++;

	if (Frame2 >= 60)
	{
		auto angle = GetAngle(m_Pos + GetCenter(), OurHero::Get()->m_Pos + Vector2(35.f, 0.f));
		ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::None, 9.f, L"Resource/Bullet/Player2.png", angle);
		Frame2 = 0;
	}


	if (Attacking == 0)
		Frame1++;

	if (Attacking == 0)
		if (Frame1 >= 120)
		{
			Attacking = 1;
			Frame1 = 0;
		}

	if (Attacking)
		Attack();

}

void LastBoss2::Draw()
{
	Unit::Draw();
}

void LastBoss2::CollideWith(Node * other)
{
	Unit::CollideWith(other);
}

void LastBoss2::Attack()
{
	static float aa;

	ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::None, 7.f, L"Resource/Bullet/Player2.png", D3DXToRadian(aa));

	aa += 11;

	if (aa >= 360)
	{
		Attacking = 0;
		aa = 0;
	}
}
