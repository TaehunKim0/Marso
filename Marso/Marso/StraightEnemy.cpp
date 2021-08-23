#include "stdafx.h"
#include "StraightEnemy.h"


StraightEnemy::StraightEnemy()
{
}

StraightEnemy::~StraightEnemy()
{
	int random = rand() % 5;

	if (random == 3)
		ObjectPool::Get()->CreateItem(m_Pos.x, m_Pos.y, ItemGroup::SpeedUp);
}

void StraightEnemy::Init(float x, float y)
{
	m_Anim = new Animation(10, 1);
	m_Anim->AddFrame(L"Resource/Enemy/Straight1.png");
	m_Anim->AddFrame(L"Resource/Enemy/Straight2.png");

	Unit::Init(x, y, Tag::Enemy, L"Straight", 2.f);
	AddChild(m_Anim);
}

void StraightEnemy::Update()
{
	Unit::Update();

	Frame1++;

	if (Frame1 >= 60)
	{
		auto angle = GetAngle(m_Pos, OurHero::Get()->m_Pos + Vector2(35.f, 0.f));
		ObjectPool::Get()->FireBullet(m_Pos + GetCenter(), Tag::Enemy, Direction::None, 9.f, L"Resource/Bullet/Player2.png", angle);
		Frame1 = 0;
	}

	Translate(0.f, 3.f);
}

void StraightEnemy::Draw()
{
	Unit::Draw();
}

void StraightEnemy::CollideWith(Node * other)
{
	Unit::CollideWith(other);
}
