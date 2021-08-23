#include "stdafx.h"
#include "MiddleBoss2.h"


MiddleBoss2::MiddleBoss2()
{
	aa = 0;
	Attacking = 0;
}


MiddleBoss2::~MiddleBoss2()
{
	int random = (rand() % 2)+1;

	if (random == 1)
		ObjectPool::Get()->CreateItem(m_Pos.x, m_Pos.y, ItemGroup::WeaponUp);

	if (random == 2)
		ObjectPool::Get()->CreateItem(m_Pos.x, m_Pos.y, ItemGroup::Add_On);
}

void MiddleBoss2::Init(Vector2 pos, Tag tag)
{
	ImBoss = 1;
	m_Anim = new Animation(10, 1);
	m_Anim->AddFrame(L"Resource/Enemy/2MiddleBoss1.png");
	m_Anim->AddFrame(L"Resource/Enemy/2MiddleBoss2.png");
	m_Anim->AddFrame(L"Resource/Enemy/2MiddleBoss3.png");

	web = Sprite::Create(L"Resource/BackGround/Web.png");
	web->UsePMatrix = 0;
	AddChild(web);

	SetPos(pos.x, pos.y);
	m_Tag = tag;
	m_Direction = Direction::Left;
	Unit::Init(pos.x, pos.y, tag, L"MiddleBoss2", 100);
	m_Size.y = m_Size.y / 2;
	AddChild(m_Anim);
}

void MiddleBoss2::Update()
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

	if (Attacking == 0)
		Frame1++;

	if (Attacking == 0)
		if (Frame1 >= 100)
		{
			Attacking = 1;
			Frame1 = 0;
		}

	if (Attacking)
		Attack();
}

void MiddleBoss2::Draw()
{
	Unit::Draw();
}

void MiddleBoss2::CollideWith(Node * other)
{
	Unit::CollideWith(other);
}

void MiddleBoss2::Attack()
{
	ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::None, 7.f, L"Resource/Bullet/Player2.png", D3DXToRadian(aa));

	aa += 11;

	if (aa >= 360)
	{
		Attacking = 0;
		aa = 0;
	}
}
