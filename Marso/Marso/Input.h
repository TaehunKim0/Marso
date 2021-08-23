#pragma once
enum class KeyState
{
	Down,
	Press,
	Up,
	None
};


class Input : public Singleton<Input>
{
private:
	int m_CurrentKey[256];
	int m_PrevKey[256];

	bool m_PrevState;
	bool m_CurrentState;

public:
	Input();
	~Input();

	void Update();
	KeyState GetKeyState(int key);

};