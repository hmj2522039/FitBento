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
	// マウスボタン
	static int m_mouse[ButtonCount];
	static int m_prevMouse[ButtonCount];	// 前フレームの入力状態

	// スペースキー
	static int m_space;
	static int m_prevSpace;	// 前フレームの入力状態

public:
	static void Update();

	// マウス座標
	static int m_mouseX;	// マウスのx座標
	static int m_mouseY;	// マウスのy座標

	static bool IsMouseDown(MouseButton button);
	static bool IsSpaceDown();
};