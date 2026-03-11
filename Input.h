#pragma once
#include "Vector2.h"

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

	// ホイール
	static int m_wheel;

	// マウス座標
	static Vec2 m_point;

	// スペースキー
	static int m_space;
	static int m_prevSpace;	// 前フレームの入力状態

public:
	static void Update();

	// 位置取得
	static Vec2 GetPoint() { return m_point; }

	// ホイール取得
	static int GetWheel() { return m_wheel; }

	// マウスボタンが押された瞬間
	static bool IsMouseDown(MouseButton button);

	// スペースキーが押された瞬間
	static bool IsSpaceDown();
};