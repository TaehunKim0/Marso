#pragma once
class Animation : public Node
{
public:
	std::vector<Sprite*> m_Anim;

	int CurrentFrame;
	int FrameCounter;
	bool AutoPlay;
	bool IsAnimEnd;
	int Delay;
	
	bool died;

	int Alpha;

	bool tick;

public:
	Animation();
	Animation(int delay , bool _auto);
	virtual ~Animation();
	void AnimTick() {
		tick = 1;
	}
	void AddFrame(std::wstring fileName);
	void Update();
	void Draw();

	void SetFrame(int frame) {
		CurrentFrame = frame;
	}
	void Died(bool a) {
		died = a;
	}

};

