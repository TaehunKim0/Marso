#pragma once
class Progress : public Node
{
public:
	bool ProgressGo;

	Sprite* progress;
	Sprite* bar;

	Sprite* Web;

	bool middle;
	bool last;

	Progress();
	~Progress();

	void Init(float x, float y);

	void Update();
	void Draw();
	void SetGo(bool a) {
		ProgressGo = a;
	}

	void StartWeb();

};

