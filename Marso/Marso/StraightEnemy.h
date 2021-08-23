#pragma once

class StraightEnemy : public Unit
{
public:
	StraightEnemy();
	virtual ~StraightEnemy();

	void Init(float x, float y);
	void Update();
	void Draw();
	void CollideWith(Node* other);
};