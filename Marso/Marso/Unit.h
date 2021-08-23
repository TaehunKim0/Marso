#pragma once
class Unit: public Node
{
public:
	Animation* m_Anim;

	float m_Speed;
	float m_Angle;
	int m_Hp;

	bool a;
	bool Died;
	bool CanCollide;

	int Frame1;
	int Frame2;
	int Frame3;

public:
	Unit();
	virtual ~Unit();

	void Init(float x, float y, Tag tag, std::wstring name, int hp);

	void Update();
	void Draw();
	void Die();
	
	virtual	void CollideWith(Node* other);
};

