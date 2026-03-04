#pragma once

// マウスの入力
enum MouseButton
{
	Left  = 0,
	Right = 1,
	ButtonCount
};

class Input
{
private:
	static int m_mouse[ButtonCount];
	static int m_prevMouse[ButtonCount];	// 前フレームの入力状態

	static int m_space;
	static int m_prevSpace;	// 前フレームの入力状態

public:
	static void Update();

	static bool IsMouseDown(MouseButton button);
	static bool IsSpaceDown();
};