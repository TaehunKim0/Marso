#include "stdafx.h"
#include "Missile.h"


Missile::Missile()
{
}

Missile::~Missile()
{
}

void Missile::Init(Vector2 pos, Tag tag, float angle, float speed, std::wstring fileName)
{
	frame = 0;
	SetPos(pos.x, pos.y);
	m_Tag = tag;
	m_Angle = angle;
	m_Speed = speed;
	bullet = Sprite::Create(fileName);

	m_Size = bullet->m_Size;

	CollisionMgr::Get()->CollideMged(this);
	AddChild(bullet);
}

void Missile::Update()
{
	Node::Update();

	frame++;

	if (frame >= 10)
	{
		if (Target == NULL)
		{
			for (auto enemy : ObjectPool::Get()->m_Enemys)
			{
				Target = enemy;
				break;
			}
		}
	}

	if (Target)
		{
			auto angle = GetAngle(m_Pos + GetCenter(), Target->m_Pos + Target->GetCenter());
			m_Angle = angle;
		}
	
	Translate(cos(m_Angle)* m_Speed, sin(m_Angle)* m_Speed);

	if (m_Pos.y <= -100)
		BulletDestroy();

	if (m_Pos.x <= 100)
		BulletDestroy();

	if (m_Pos.x >= 1280)
		BulletDestroy();

	if (m_Pos.y >= 720)
		BulletDestroy();

}

void Missile::Draw()
{
	Bullet::Draw();
}

void Missile::CollideWith(Node * other)
{
	Bullet::CollideWith(other);
}
