#pragma once
enum class Tag
{
	Player,
	Enemy,
	Item,
	Structure,
	None
};

enum class Direction
{
	Up,
	Down,
	Right,
	Left,
	None
};

enum class State
{
	Idle,
	Attack,
	Move
};

class Node
{
public:
	std::vector<Node*> m_Children;
	std::vector<Node*> m_DeChildren;

	Node* m_Parent;
	Vector2 m_Pos;
	Vector2 m_Scale;
	Vector2 m_Size;
	int tag;
	float m_Rotation;
	std::wstring m_Name;
	Tag m_Tag;
	Direction m_Direction;
	State m_State;
	bool IsActive;

	bool UsePMatrix;

	bool ImBoss;

public:
	Node();
	virtual ~Node();

	Vector2 GetCenter() {
		return Vector2(m_Size.x / 2, m_Size.y / 2);
	}

	virtual void Update();
	virtual void Draw();
	virtual void JIN() {}
	float GetAngle(Vector2 pos1, Vector2 pos2);
	void AddChild(Node* child);
	void RemoveChild(Node* child);
	void Destroy();
	
	virtual void CollideWith(Node* other);

	D3DXMATRIX GetMatrix();
	void Translate(float x, float y) {
		m_Pos.x += x;
		m_Pos.y += y;
	}

	void SetPos(float x, float y) {
		m_Pos.x = x;
		m_Pos.y = y;
	}
	void Translate(Vector2 pos) {
		m_Pos += pos;
	}
};

