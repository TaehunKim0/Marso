#include "stdafx.h"
#include "DashEnemy.h"


DashEnemy::DashEnemy()
{
}

DashEnemy::~DashEnemy()
{
	int random = rand() % 7;

	if (random == 5)
		ObjectPool::Get()->CreateItem(m_Pos.x, m_Pos.y, ItemGroup::HpUp);

}

void DashEnemy::Init(float x, float y)
{
	m_Anim = new Animation(10, 1);
	m_Anim->AddFrame(L"Resource/Enemy/Dash1.png");
	m_Anim->AddFrame(L"Resource/Enemy/Dash2.png");

	m_Speed = 5.f;

	Unit::Init(x, y, Tag::Enemy, L"Dash", 2.f);
	auto angle = GetAngle(m_Pos, OurHero::Get()->m_Pos + Vector2{ 49.f,-30.f });

	m_Angle = angle;

	//플레이어 인스턴스

	AddChild(m_Anim);
}

void DashEnemy::Update()
{
	Unit::Update();
	
	Translate(cos(m_Angle) *m_Speed, sin(m_Angle)* m_Speed);
}

void DashEnemy::Draw()
{
	Unit::Draw();
}

void DashEnemy::CollideWith(Node * other)
{
	Unit::CollideWith(other);
}