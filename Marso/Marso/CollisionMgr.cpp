#include "stdafx.h"
#include "CollisionMgr.h"


CollisionMgr::CollisionMgr()
{
}


CollisionMgr::~CollisionMgr()
{
}

void CollisionMgr::Update()
{
	int as = 0;

	for (auto node1 : m_Collisions)
	{
		for (auto node2 : m_Collisions)
		{
			if (node1 != node2)
			{
				if(node1 && node2)
				if (node1->m_Tag != node2->m_Tag)
				{
					if (BoxCollisionCheck(node1, node2))
					{
						++as;
						("as : %d\n", as);

						node1->CollideWith(node2);
						node2->CollideWith(node1);
					}
				}
			}
		}
	}
}

bool CollisionMgr::BoxCollisionCheck(Node * node1, Node * node2)
{
	auto node1right = node1->m_Pos.x + node1->m_Size.x;
	auto node2right = node2->m_Pos.x + node2->m_Size.x;

	auto node1Bottom = node1->m_Pos.y + node1->m_Size.y;
	auto node2Bottom = node2->m_Pos.y + node2->m_Size.y;

	if (node1->m_Pos.x < node2right && node1->m_Pos.y < node2Bottom)
	{
		if (node1right > node2->m_Pos.x && node1Bottom > node2->m_Pos.y)
		{
			return true;
		}
	}

	return false;
}

bool CollisionMgr::BoxCheck(Node * node1, Node * node2)
{
	return true;
}

void CollisionMgr::CollideMged(Node * node)
{
	m_Collisions.push_back(node);
}

void CollisionMgr::DestroyCollision(Node * node)
{
	auto iter = std::find(m_Collisions.begin(), m_Collisions.end(), node);
	if (iter != m_Collisions.end())
	{
		m_Collisions.erase(iter);
	}
}
