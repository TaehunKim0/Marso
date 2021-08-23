#pragma once
class BackGround;
class OurHero;
class MiddleBoss1;
class LastBoss1;
class Progress;

class Stage1 : public Scene
{
	BackGround* backGround;
	OurHero* Player;
	Score* score;
	Progress* progress;

	Sprite* Retry;
	Sprite* Black;
	Sprite* GameOver;
	Animation* RetryButton;

	bool spawn;

	bool middleBossed;
	bool lastBossed;

	bool a;
	bool aaa;
	bool bbb;
	int ff;
	bool f;
	bool yes;

	int frame1;
	int frame2;
	int frame3;

	int frame4;
	bool GameEnd;


	MiddleBoss1 * middle;
	LastBoss1* last;

public:
	Stage1();
	virtual ~Stage1();

	void OnEnter();
	void OnExit();

	void Update();
	void Draw();

	void SpawnEnemys();

	void SpawnMiddle(int x, int y);
	void SpawnLast(int x, int y);

};