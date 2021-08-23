#pragma once
class Bullet : public Node
{
public:
	float m_Angle;
	float m_Speed;

	Sprite* bullet;

public:
	Bullet();

	Bullet(Vector2 pos, Tag tag, Direction direction, float speed, std::wstring fileName, float angle);
	virtual ~Bullet();

	void BulletDestroy() {
		Destroy();
		CollisionMgr::Get()->DestroyCollision(this);
	}

	virtual void Update();
	virtual void Draw();
	virtual void CollideWith(Node* other);
};