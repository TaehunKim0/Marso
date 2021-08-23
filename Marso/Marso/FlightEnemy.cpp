#include "stdafx.h"
#include "FlightEnemy.h"


FlightEnemy::FlightEnemy()
{
}


FlightEnemy::~FlightEnemy()
{
	int random = rand() % 5;

	if (random == 3)
		ObjectPool::Get()->CreateItem(m_Pos.x, m_Pos.y, ItemGroup::Add_On);
}

void FlightEnemy::Init(float x, float y)
{
	m_Anim = new Animation(10,1);
	m_Anim->AddFrame(L"Resource/Enemy/Flight1.png");
	m_Anim->AddFrame(L"Resource/Enemy/Flight2.png");

	Unit::Init(x, y, Tag::Enemy, L"Flight", 2.f);
	AddChild(m_Anim);
}

void FlightEnemy::Update()
{
	Unit::Update();

	Translate(0.f, 2.f);

}

void FlightEnemy::Draw()
{
	Unit::Draw();
}

void FlightEnemy::CollideWith(Node * other)
{
	Unit::CollideWith(other);
}