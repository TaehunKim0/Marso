#pragma once
//32πÊ«‚ + ¿Øµµ≈∫

class LastBoss2 : public Unit
{
public:
	LastBoss2();
	virtual ~LastBoss2();
	bool Attacking;
	void Init(Vector2 pos, Tag tag);
	
	void Update();
	void Draw();
	void CollideWith(Node* other);

	void Attack();
};

