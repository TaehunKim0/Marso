#pragma once
class DivideEnemy : public Unit
{
public:
	DivideEnemy();
	virtual ~DivideEnemy();

	void Init(float x, float y);
	void Update();
	void Draw();
	void CollideWith(Node* other);
};

class Divided : public Unit
{
public:
	Divided();
	~Divided();

	void Init(float x, float y , float angle);

	void Update();
	void Draw();
	void CollideWith(Node* other);
};