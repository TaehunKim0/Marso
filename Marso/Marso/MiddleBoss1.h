#pragma once
//16πÊ«‚

class MiddleBoss1 : public Unit
{
public:
	MiddleBoss1();
	virtual ~MiddleBoss1();

	void Init(Vector2 pos, Tag tag);
	int a;
	void Update();
	void Draw();
	void CollideWith(Node* other);

	void Attack();
	bool Attacking;
};

