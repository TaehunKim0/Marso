#pragma once
class Score : public Node , public Singleton<Score>
{
public:
	Animation* S1;
	Animation* S2;
	Animation* S3;

	Sprite * scoreback;

	int S1Count;
	int S2Count;
	int S3Count;
	int score;

public:
	Score();
	virtual ~Score();

	void Update();
	void Draw();

	void Calc();
	void ScoreUp() {
		score += 1;
		Calc();
	}
};

