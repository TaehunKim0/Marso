#pragma once
//32 πÊ«‚

class MiddleBoss2 : public Unit
{
public:
	MiddleBoss2();
	virtual ~MiddleBoss2();
	int aa;
	Sprite* web;

	bool Attacking;
	void Init(Vector2 pos, Tag tag);

	void Update();
	void Draw();
	void CollideWith(Node* other);

	void Attack();
};

