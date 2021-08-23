#include "stdafx.h"
#include "Input.h"


Input::Input()
{
	ZeroMemory(m_CurrentKey, sizeof(m_CurrentKey));
	ZeroMemory(m_PrevKey, sizeof(m_PrevKey));

	m_CurrentState = false;
	m_PrevState = false;
}

Input::~Input()
{
}

void Input::Update()
{
	for (int i = 0; i < 256; i++)
	{
		m_PrevKey[i] = m_CurrentKey[i];
		m_CurrentKey[i] = static_cast<bool>(GetAsyncKeyState(i));
	}
}

KeyState Input::GetKeyState(int key)
{
	m_PrevState = m_PrevKey[key];
	m_CurrentState = m_CurrentKey[key];

	if (m_PrevState == true && m_CurrentState == true)
		return KeyState::Press;

	else if (m_PrevState == true && m_CurrentState == false)
		return KeyState::Up;

	else if (m_PrevState == false && m_CurrentState == true)
		return KeyState::Down;


	return KeyState::None;
}
