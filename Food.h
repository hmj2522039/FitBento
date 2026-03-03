#pragma once

class Food
{
private:
	// おかず
	int m_foodX, m_foodY;	// おかずの中心座標
	int m_foodW, m_foodH;	// 判定矩形の高さ、幅
	float m_rectRange;		// 中心からの距離

	// マウス操作関連
	int m_mouseX; // マウスのx座標
	int m_mouseY; // マウスのy座標
	int m_clicked; // クリックされたか
	bool m_isHold; // つかんでいるか

public:
	Food(int x, int y, int w, int h, float range);

	void Update();
	void Draw();
};