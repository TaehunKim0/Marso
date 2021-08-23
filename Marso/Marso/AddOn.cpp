#include "stdafx.h"
#include "AddOn.h"


AddOn::AddOn()
{
	Frame = 0;
	Count = 0;
}

AddOn::~AddOn()
{
}

void AddOn::Init(int count)
{
	Count = count;

	if (count == 1) {
		addon = Sprite::Create(L"Resource/Player/Addon1.png");
		SetPos(120.f, 30.f);
	}
	if (count == 2) {
		addon = Sprite::Create(L"Resource/Player/Addon2.png");
		SetPos(150.f, 30.f);
	}
	if (count == 3) {
		addon = Sprite::Create(L"Resource/Player/Addon3.png");
		SetPos(-60.f, 30.f);
	}
	if (count == 4) {
		addon = Sprite::Create(L"Resource/Player/Addon4.png");
		SetPos(-90.f, 30.f);
	}

	AddChild(addon);
}

void AddOn::Update()
{
	Node::Update();

	Frame++;

	if (Frame >= 60)
	{
		if (Count == 1)
		{
			ObjectPool::Get()->FireBullet(m_Pos + Vector2(10.f,0.f) + m_Parent->m_Pos, Tag::Player, Direction::None, 7.f, L"Resource/Bullet/AddOn1.png", D3DXToRadian(-90));
		}
		if (Count == 2)
		{
			ObjectPool::Get()->FireBullet(m_Pos + Vector2(10.f, 0.f) + m_Parent->m_Pos, Tag::Player, Direction::None, 7.f, L"Resource/Bullet/AddOn2.png", D3DXToRadian(-90));
		}
		if (Count == 3)
		{
			ObjectPool::Get()->FireBullet(m_Pos + Vector2(10.f, 0.f) + m_Parent->m_Pos, Tag::Player, Direction::None, 7.f, L"Resource/Bullet/AddOn3.png", D3DXToRadian(-90));
			
		}
		if (Count == 4)
		{
			ObjectPool::Get()->FireBullet(m_Pos + Vector2(10.f, 0.f) + m_Parent->m_Pos, Tag::Player, Direction::None, 7.f, L"Resource/Bullet/AddOn4.png", D3DXToRadian(-90));
		}
		Frame = 0;
	}
}

void AddOn::Draw()
{
	Node::Draw();
}
