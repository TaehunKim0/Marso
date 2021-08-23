#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
}

Bullet::Bullet(Vector2 pos, Tag tag, Direction direction, float speed, std::wstring fileName, float angle)
{
	SetPos(pos.x ,pos.y);
	m_Direction = direction;
	m_Speed = speed;
	UsePMatrix = 0;

	bullet = Sprite::Create(fileName);
	m_Angle = angle;
	m_Tag = tag;
	CollisionMgr::Get()->CollideMged(this);
	AddChild(bullet);
}

Bullet::~Bullet()
{
	
	//ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide);
}

void Bullet::Update()
{
	Node::Update();
	
	Translate(cos(m_Angle)* m_Speed, sin(m_Angle)* m_Speed);

	if (m_Pos.y <= -100)
		BulletDestroy();

	if (m_Pos.y >= 720)
		BulletDestroy();
}

void Bullet::Draw()
{
	Node::Draw();
}

void Bullet::CollideWith(Node * other)
{
	if (other->m_Tag != Tag::Item)
	{
		if (other->m_Tag != m_Tag)
		{
			if (m_Tag == Tag::Player)
			{
				ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide, D3DXToRadian(-120));
				ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide, D3DXToRadian(-90));
				ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide, D3DXToRadian(-60));

				ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide, D3DXToRadian(0));
				ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide, D3DXToRadian(-180));

				ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide, D3DXToRadian(120));
				ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide, D3DXToRadian(90));
				ObjectPool::Get()->CreateEffect(m_Pos.x, m_Pos.y, EffectType::BulletCollide, D3DXToRadian(60));
			}
			BulletDestroy();
		}
	}
}