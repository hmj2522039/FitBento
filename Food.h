#pragma once
#include <vector>

// 複数矩形表示用
struct BoxPart
{
	int offsetX, offsetY;	// 中心からの相対位置
	int width, height;		// 幅、高さ
};

class Food
{
private:
	// おかず
	int m_foodX, m_foodY;	// おかずの中心座標

	bool m_isHold;	// つかんでいるか
	bool m_isLocked;// 既に移動させたものかどうか

	std::vector<BoxPart> m_parts;

public:
	Food(int x, int y);

	void AddBoxPart(const BoxPart& part);

	void SetHold();	// つかむ
	bool CheckHold() const;	// つかめるかどうかの判定
	bool IsLocked() const;

	void Update();
	void Draw();
};