#pragma once

class MiddleBoss2;
class LastBoss2;
class BackGround;
class Score;
class Progress;

class Stage2 : public Scene
{
public:
	MiddleBoss2* middle;
	LastBoss2* last;
	OurHero* Player;

	BackGround* backGround;
	Score* score;
	Progress* progress;
	Sprite* Retry;
	Sprite* Black;
	Sprite* GameOver;
	Animation* RetryButton;
	bool spawn;

	bool middleBossed;
	bool lastBossed;

	int frame1;
	int frame2;
	int frame3;

	bool a;
	bool aaa;
	bool bbb;
	int ff;
	bool f;
	bool yes;

public:
	Stage2();
	virtual ~Stage2();

	void OnEnter();
	void OnExit();

	void Update();
	void Draw();

	void SpawnMiddle(int x, int y);
	void SpawnLast(int x, int y);

	void SpawnEnemys();
};

