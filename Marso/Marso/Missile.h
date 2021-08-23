#pragma once
class Missile : public Bullet
{
	Node* Target;
	Sprite* bulelt;
	int frame;
public:
	Missile();
	~Missile();

	void Init(Vector2 pos, Tag tag, float angle, float speed, std::wstring fileName);

	void Update();
	void Draw();
	void CollideWith(Node* other);
};