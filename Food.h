#pragma once
#include <vector>
#include "Vector2.h"

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
	Vec2 m_foodPos;	// おかずの座標

	bool m_isHold;	// つかんでいるか
	bool m_isLocked;// 既に移動させたものかどうか

	int m_angle;	// おかずの角度

	std::vector<BoxPart> m_parts;

public:
	Food(int x, int y);

	void AddBoxPart(const BoxPart& part);	// 当たり判定用のboxパーツを追加する
	void SetHold();	// つかむ

	void Rotate();	// 回転
	bool IsLocked() const; // 設置済み

	Vec2 GetPos()const { return m_foodPos; }
	int GetAngle() const { return m_angle; }
	const std::vector<BoxPart>& GetParts() const { return m_parts; }

	void Update();
	void Draw();
};