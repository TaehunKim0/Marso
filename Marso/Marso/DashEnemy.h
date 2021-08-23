#pragma once
class DashEnemy : public Unit
{
public:
	DashEnemy();
	virtual ~DashEnemy();

	void Init(float x, float y);
	void Update();
	void Draw();
	void CollideWith(Node* other);
};