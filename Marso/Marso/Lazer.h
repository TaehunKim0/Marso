#pragma once
class Lazer : public Node
{
	Node* Target;
	Sprite* lazer;

	int frame;
	float d;
public:
	Lazer();
	~Lazer();

	void Init(Vector2 pos, Tag tag);

	void Update();
	void Draw();
	void CollideWith(Node* other);

};

