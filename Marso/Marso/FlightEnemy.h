#pragma once
class FlightEnemy : public Unit
{
public:
	FlightEnemy();
	virtual ~FlightEnemy();

	void Init(float x, float y);

	void Update();
	void Draw();
	void CollideWith(Node* other);
};