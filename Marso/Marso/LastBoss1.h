#pragma once

//16πÊ«‚ + ¿Øµµ≈∫

class LastBoss1 : public Unit
{
	bool Attacking;
	Sprite* web;
public:
	LastBoss1();
	virtual ~LastBoss1();

	int aa;
	void Init(Vector2 pos, Tag tag);

	void Update();
	void Draw();
	void CollideWith(Node* other);

	void Attack();
};

