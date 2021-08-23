#pragma once
class Meteor : public Node
{

	Animation * m_Sprite;


public:
	Meteor();
	~Meteor();

	void Init(float x, float y);

	void Update();
	void Draw();

	void CollideWith(Node* other);

};

