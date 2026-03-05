#include "Input.h"
#include "DxLib.h"

int Input::m_mouseX = 0;
int Input::m_mouseY = 0;

int Input::m_mouse[ButtonCount] = { 0 };
int Input::m_prevMouse[ButtonCount] = { 0 };

int Input::m_space = 0;
int Input::m_prevSpace = 0;

void Input::Update()
{
	GetMousePoint(&m_mouseX, &m_mouseY);

	// 前フレームの状態
	for (int i = 0; i < ButtonCount; i++)
	{
		m_prevMouse[i] = m_mouse[i];
	}

	m_prevSpace = m_space;


	// 現フレームの入力状態を取得
	int mouseClick = GetMouseInput();
	m_mouse[Left]  = (mouseClick & MOUSE_INPUT_LEFT);
	m_mouse[Right] = (mouseClick & MOUSE_INPUT_RIGHT);

	m_space = CheckHitKey(KEY_INPUT_SPACE);
}

bool Input::IsMouseDown(MouseButton button)
{
	return (m_mouse[button] && !m_prevMouse[button]);
}

bool Input::IsSpaceDown()
{
	return (m_space && !m_prevSpace);
}