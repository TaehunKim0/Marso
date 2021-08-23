#pragma once
class BackGround: public Node
{
	Sprite* back1;
	Sprite* back2;

	Sprite* Mark;
	Sprite* Jull;
	int sFrame;
	int ssFrame;

	
	int randomX;
public:
	BackGround();
	virtual ~BackGround();

	void Init(int stage);
	void Update();
	void Draw();

	bool Meteored;
	void FireMetor(int x, int y);
};


