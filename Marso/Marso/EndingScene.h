#pragma once

class EndingScene : public Scene
{
	Sprite* Ending;

public:
	EndingScene();
	virtual ~EndingScene();

	void OnEnter();
	void OnExit();

	void Update();
	void Draw();

};

