#pragma once
class CollisionMgr : public Singleton<CollisionMgr>
{
private:
	std::vector<Node*> m_Collisions;

public:
	CollisionMgr();
	~CollisionMgr();

	void Update();
	void Release() {
		m_Collisions.clear();
	}
	bool BoxCollisionCheck(Node* node1, Node* node2);
	bool BoxCheck(Node* node1, Node* node2);

	void CollideMged(Node* node);
	void DestroyCollision(Node* node);
};

