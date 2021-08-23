#pragma once
class AddOn : public Node
{
private:
	int Frame;
	Sprite* addon;
	int Count;

public:
	AddOn();
	~AddOn();

	void Init(int count);
	void Update();
	void Draw();
};

