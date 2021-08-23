#include "stdafx.h"
#include "Node.h"


Node::Node()
	: m_Name(L"")
	, m_Parent(NULL)
	, m_Pos(Vector2{0.f,0.f})
	, m_Rotation(0.f)
	, m_Scale(Vector2{1.f,1.f})
	, m_Tag(Tag::None)
	, UsePMatrix(1)
	, m_Size(0.f,0.f)
	, m_Direction(Direction::None)
	, m_State(State::Idle)
	, IsActive(true)
	, tag(0)
	, ImBoss(0)
{
}

Node::~Node()
{
	for (int i = 0; i < m_Children.size(); i++)
	{
		SAFE_DELETE(m_Children[i]);
		//("³ëµå Á¦°ÅµÊ");
	}
	m_Children.clear();
}

void Node::Update()
{
	while (!m_DeChildren.empty())
	{
		RemoveChild(m_DeChildren.front());
		m_DeChildren.pop_back();
	}

	if(IsActive)
		for (int i = 0; i < m_Children.size(); i++)
		{
			m_Children[i]->Update();
		}
}

void Node::Draw()
{
	if (IsActive)
		for (int i = 0; i < m_Children.size(); i++)
		{
			m_Children[i]->Draw();
		}
}

float Node::GetAngle(Vector2 pos1, Vector2 pos2)
{
	float m_fDegree = atan2f((float)pos2.y - pos1.y, (float)pos2.x - pos1.x);

	return (m_fDegree);
}

void Node::AddChild(Node * child)
{
	m_Children.push_back(child);
	child->m_Parent = this;
}

void Node::RemoveChild(Node * child)
{
	if (m_Children.empty())
		return;

	if (child == nullptr)
		return;

	std::vector<Node*>::iterator iter = std::find(m_Children.begin(), m_Children.end(), child);
	if (iter != m_Children.end())
	{
		m_Children.erase(iter);
		SAFE_DELETE(child);
		//("³ëµå Á¦°ÅµÊ");
	}
}

void Node::Destroy()
{
	m_Parent->m_DeChildren.push_back(this);
}

void Node::CollideWith(Node * other)
{

}

D3DXMATRIX Node::GetMatrix()
{
	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
	D3DXMatrixTransformation2D(&m, NULL, NULL, &m_Scale, NULL, m_Rotation, &m_Pos);

	if(UsePMatrix)
		if (m_Parent)
			m *= m_Parent->GetMatrix();

	return m;
}
