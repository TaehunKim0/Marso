#pragma once
class IntroScene : public Scene
{
public:
	IntroScene();
	virtual ~IntroScene();

	void OnEnter();
	void OnExit();

	void Update();
	void Draw();
};