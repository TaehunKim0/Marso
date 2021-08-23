#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	m_Tag = Tag::Item;
	died = 0;
} 

Item::~Item()
{
}

void Item::Init(float x, float y, ItemGroup item)
{
	SetPos(x, y);

	switch (item)
	{
	case ItemGroup::SpeedUp:
		m_Sprite = Sprite::Create(L"Resource/Item/SpeedUp.png");
		m_Name = L"SpeedUp";
		break;

	case ItemGroup::HpUp:
		m_Sprite = Sprite::Create(L"Resource/Item/HpUp.png");
		m_Name = L"HpUp";
		break;

	case ItemGroup::WeaponUp:
		m_Sprite = Sprite::Create(L"Resource/Item/WeaponUp.png");
		m_Name = L"WeaponUp";
		break;

	case ItemGroup::Add_On:
		m_Sprite = Sprite::Create(L"Resource/Item/AddOn.png");
		m_Name = L"Add_On";
		break;

	}

	m_Tag = Tag::Item;
	m_Size = m_Sprite->m_Size;

	m_Scale = m_Scale * 1.5;
	m_Size = m_Size * 1.5;

	CollisionMgr::Get()->CollideMged(this);
	AddChild(m_Sprite);
}

void Item::Update()
{
	Node::Update();

	Translate(0.f, 1.f);

	if (m_Pos.y >= 720)
	{
		CollisionMgr::Get()->DestroyCollision(this);
		Destroy();
	}

	if (died)
	{
		CollisionMgr::Get()->DestroyCollision(this);
		Destroy();
	}

}

void Item::Draw()
{
	Node::Draw();
}

void Item::CollideWith(Node * other)
{
	if (other->m_Name == L"Hero")
	{
		died = 1;
	}
}