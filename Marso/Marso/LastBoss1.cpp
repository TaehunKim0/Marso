#include "stdafx.h"
#include "LastBoss1.h"


LastBoss1::LastBoss1()
{
	Attacking = 0; aa = 0;
}

LastBoss1::~LastBoss1()
{
	ObjectPool::Get()->CreateItem(m_Pos.x, m_Pos.y, ItemGroup::WeaponUp);
}

void LastBoss1::Init(Vector2 pos, Tag tag)
{
	ImBoss = 1;
	m_Anim = new Animation(10, 1);
	m_Anim->AddFrame(L"Resource/Enemy/LastBoss1.png");
	m_Anim->AddFrame(L"Resource/Enemy/LastBoss22.png");
	m_Anim->AddFrame(L"Resource/Enemy/LastBoss3.png");

	SetPos(pos.x, pos.y);
	m_Tag = tag;
	m_Direction = Direction::Left;
	

	web = Sprite::Create(L"Resource/BackGround/Web.png");
	web->UsePMatrix = 0;
	AddChild(web);

	Unit::Init(pos.x, pos.y, tag, L"LastBoss1", 500);

	m_Size.y = m_Size.y / 2;
	AddChild(m_Anim);
}

void LastBoss1::Update()
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
	Frame1++;

	if (Frame1 >= 60)
	{
		auto angle = GetAngle(m_Pos + GetCenter(), OurHero::Get()->m_Pos + Vector2(35.f, 0.f));
		ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::None, 9.f, L"Resource/Bullet/Player2.png", angle);
		Frame1 = 0;
	}

	("Frame2 : %d\n", Frame2);

	if (Attacking == 0)
		Frame2++;

	if (Attacking == 0)
		if (Frame2 >= 360)
		{
			Attacking = 1;
			Frame2 = 0;
		}

	if (Attacking)
		Attack();

}

void LastBoss1::Draw()
{
	Unit::Draw();
}

void LastBoss1::CollideWith(Node * other)
{
	Unit::CollideWith(other);
}

void LastBoss1::Attack()
{
	ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::None, 7.f, L"Resource/Bullet/Player2.png", D3DXToRadian(aa));

	aa += 22;

	if (aa >= 360)
	{
		Attacking = 0;
		aa = 0;
	}
}