#include "stdafx.h"
#include "Hp_UI.h"


void Hp_UI::Init(float x, float y)
{
	m_Hp = Sprite::Create(L"Resource/UI/Player_HpBar.png");
	m_Hp->UseMRect = 0;

	SetRect(&m_Hp->m_Rect, 0, 0, m_Hp->m_Size.x, m_Hp->m_Size.y);

	SetPos(x, y);
	AddChild(m_Hp);
}

void Hp_UI::Update()
{
	Node::Update();
}

void Hp_UI::Draw()
{
	Node::Draw();
}

void Hp_UI::PlayerDmgd()
{
	static int dt;

	dt -= 10;

	SetRect(&m_Hp->m_Rect, 0, 0, m_Hp->m_Size.x - dt, m_Hp->m_Size.y);

}
