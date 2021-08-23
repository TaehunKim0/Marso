#include "stdafx.h"
#include "Unit.h"


Unit::Unit()
	: m_Hp(1.f)
	, m_Angle(0.f)
	, Died(0)
	, Frame1(0)
	, Frame2(0)
	, m_Speed(0.f)
	, Frame3(0)
{
	CanCollide = 1;
}

Unit::~Unit()
{
	ObjectPool::Get()->DestroyEnemy(this);
	//ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::EnemyDead);
}

void Unit::Init(float x, float y, Tag tag, std::wstring name , int hp)
{
	SetPos(x, y);
	m_Tag = tag;
	m_Name = name;
	m_Hp = hp;
	
	m_Size = m_Anim->m_Size;

	CollisionMgr::Get()->CollideMged(this);
}

void Unit::Update()
{
	Node::Update();

	if (m_Name != L"Hero")
	{
		if (m_Pos.y >= 720)
			Died = 1;

		if (m_Hp <= 0)
			Died = 1;

		Die();
	}
}

void Unit::Draw()
{
	Node::Draw();
}

void Unit::Die()
{
	if (Died)
	{
 		CollisionMgr::Get()->DestroyCollision(this);
		Destroy();
	}
}

void Unit::CollideWith(Node * other)
{
	if (other->m_Tag == Tag::Item)
		return;

	if (other->m_Tag != m_Tag)
	{
		//Áøµ¿
		m_Parent->JIN();

		m_Hp -= 1;
		m_Anim->AnimTick();
	}

	if (m_Hp <= 0)
	{
	
		Score::Get()->ScoreUp();
	}
}