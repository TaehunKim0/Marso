#pragma once
class Scene: public Node
{
	int frame;
	int a; int b;

	int TotalFrame;
	bool jin;
public:
	Scene();
	virtual ~Scene();

	virtual void OnEnter() {}
	virtual void OnExit() {}
	virtual void Update() {
		Node::Update();

		TotalFrame++;

		if(jin)
			if (TotalFrame % 3 == 0)
			{
				b++;

				if (b < 5)
				{
					Translate(a, 0.f);
					a *= -1;
				}
				else
				{
					b = 0;
					jin = 0;
					return;
				}
			}

	}
	virtual void Draw() {
		Node::Draw();
	}

	void JIN();

};

