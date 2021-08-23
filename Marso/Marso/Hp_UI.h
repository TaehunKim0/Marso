#pragma once
class Hp_UI : public Node
{
public:
	Sprite* m_Hp;

public:
	Hp_UI() {}
	virtual ~Hp_UI() {}

	void Init(float x, float y);

	void Update();
	void Draw();
	void PlayerDmgd();
};