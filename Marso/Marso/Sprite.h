#pragma once
class Sprite : public Node
{
public:
	Texture* m_Texture;
	Vector2 m_Size;
	RECT m_Rect;
	bool UseMRect;

	bool tick;
	int Alpha;
	int frame;
	bool died;

public:
	Sprite();
	~Sprite();

	static Sprite* Create(std::wstring fileName);
	bool Init(std::wstring fileName);

	void Update() {}
	void Draw();
	void Tick() {
		tick = 1;
	}
	void Died() {
		died = 1;
	}
};

