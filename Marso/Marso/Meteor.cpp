#include "stdafx.h"
#include "Meteor.h"


Meteor::Meteor()
{
}


Meteor::~Meteor()
{
}

void Meteor::Init(float x, float y)
{
	SetPos(x, y);

	m_Sprite = new Animation(3, 1);
	m_Sprite->AddFrame(L"Resource/BackGround/Meteor1.png");
	m_Sprite->AddFrame(L"Resource/BackGround/Meteor2.png");
	m_Sprite->AddFrame(L"Resource/BackGround/Meteor1.png");
	m_Sprite->AddFrame(L"Resource/BackGround/Meteor3.png");

	m_Size.x = 141.f;
	m_Size.y = 226.f;

	m_Scale = m_Scale / 3;

	CollisionMgr::Get()->CollideMged(this);
	m_Tag = Tag::Enemy;

	m_Name = L"Meteor";

	AddChild(m_Sprite);
}

void Meteor::Update()
{
	Node::Update();

	Translate(0.f, 10.f);

	if (m_Pos.y >= 720)
	{
		Destroy();
		CollisionMgr::Get()->DestroyCollision(this);
	}

}

void Meteor::Draw()
{
	Node::Draw();
}

void Meteor::CollideWith(Node * other)
{


}
