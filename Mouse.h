#pragma once
#include "DxLib.h"

class Mouse
{
private:
	int m_mouseX; // マウスのx座標
	int m_mouseY; // マウスのy座標

	int m_clicked; // クリックされたか
	bool m_isHold = false; // つかんでいるか

	// boxの座標(仮)
	int m_size = 100;
	int m_bx = 100;
	int m_by = 100;

public:
	void Update();
	void Draw();
};