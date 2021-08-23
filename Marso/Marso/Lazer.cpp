#include "stdafx.h"
#include "Lazer.h"


Lazer::Lazer()
{
	frame = 0;
	d = 0.f;
}


Lazer::~Lazer()
{
	//ObjectPool::Get()->CreateEffect(Target->m_Pos.x, Target->m_Pos.y, EffectType::BulletCollide);
}

void Lazer::Init(Vector2 pos, Tag tag)
{
	SetPos(pos.x, pos.y);
	m_Tag = tag;
	Target = nullptr;
	
}

void Lazer::Update()
{
	Node::Update();

	for (auto enemy : ObjectPool::Get()->m_Enemys)
	{
		if(Target == nullptr)
		if (enemy)
		{
			lazer = Sprite::Create(L"Resource/Bullet/Lazer.png");

			auto angle = GetAngle(m_Pos, enemy->m_Pos + enemy->GetCenter());
			lazer->m_Rotation = angle;

			auto distance = sqrt(pow(enemy->m_Pos.x - lazer->m_Pos.x, 2) + pow(enemy->m_Pos.y - lazer->m_Pos.y, 2));
			d = distance / lazer->m_Size.x;

			lazer->m_Scale.x = d;
			lazer->m_Scale.y = lazer->m_Scale.y / 2;

			if (!(enemy->ImBoss))
			{
				enemy->Died = 1;
			}

			AddChild(lazer);
			Target = enemy;
		}
	}

	lazer->m_Scale.x = d;

		frame++;
		if (frame >= 10)
		{
			Destroy();
		}
	
}

void Lazer::Draw()
{
	Node::Draw();
}

void Lazer::CollideWith(Node * other)
{

}
