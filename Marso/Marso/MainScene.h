#pragma once

class MainScene : public Scene
{
public:
	Sprite* BackGround;

	Sprite* Introduce;
	Sprite* Method;

	Animation* m_Anim;

	int mainCount;

public:
	MainScene();
	virtual ~MainScene();

	void OnEnter();
	void OnExit();

	void Update();
	void Draw();
};