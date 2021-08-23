#include "stdafx.h"
#include "DivideEnemy.h"


DivideEnemy::DivideEnemy()
{
}


DivideEnemy::~DivideEnemy()
{
}

void DivideEnemy::Init(float x, float y)
{
	m_Anim = new Animation(10, 1);
	m_Anim->AddFrame(L"Resource/Enemy/Divided1.png");
	m_Anim->AddFrame(L"Resource/Enemy/Divided2.png");

	Unit::Init(x, y, Tag::Enemy, L"Divide", 2.f);
	AddChild(m_Anim);
}

void DivideEnemy::Update()
{
	Unit::Update();

	Translate(0.f, 2.f);

	if (Died)
	{
		ObjectPool::Get()->SpawnDivided(m_Pos.x, m_Pos.y, D3DXToRadian(45));
		ObjectPool::Get()->SpawnDivided(m_Pos.x, m_Pos.y, D3DXToRadian(90));
		ObjectPool::Get()->SpawnDivided(m_Pos.x, m_Pos.y, D3DXToRadian(135));
	}
}

void DivideEnemy::Draw()
{
	Unit::Draw();
}

void DivideEnemy::CollideWith(Node * other)
{
	if (other->m_Tag == Tag::Player)
		m_Hp -= 0.5f;
}


//////////////////////////////////////

Divided::Divided()
{
}

Divided::~Divided()
{
	int random = rand() % 5;

	if (random == 3)
		ObjectPool::Get()->CreateItem(m_Pos.x, m_Pos.y, ItemGroup::WeaponUp);
}

void Divided::Init(float x, float y, float angle)
{
	m_Anim = new Animation(10, 1);

	m_Anim->AddFrame(L"Resource/Enemy/Divided1.png");
	m_Anim->AddFrame(L"Resource/Enemy/Divided2.png");

	m_Angle = angle;

	Unit::Init(x, y, Tag::Enemy, L"Divided", 2);

	m_Scale = m_Scale / 2;
	m_Size = m_Size / 2;

	AddChild(m_Anim);
}

void Divided::Update()
{
	Unit::Update();

	Frame1++;

	if (Frame1 <= 5)
	{
		Translate(cos(m_Angle) * 15.f, sin(m_Angle) * 15.f);
	}

	else
		Translate(cos(m_Angle) * 1.f, sin(m_Angle) * 1.f);
}

void Divided::Draw()
{
	Unit::Draw();
}

void Divided::CollideWith(Node * other)
{
	Unit::CollideWith(other);

	if (m_Hp <= 0)
	{
		auto angle = GetAngle(m_Pos + GetCenter(), OurHero::Get()->m_Pos);

		ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::Up, 5.f, L"Resource/Bullet/Player2.png", angle);
		ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::Up, 5.f, L"Resource/Bullet/Player2.png", angle - 0.3f);
		ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::Up, 5.f, L"Resource/Bullet/Player2.png", angle + 0.3f);
	}

}