#pragma once
#include <vector>
#include "Food.h"
#include "BentoSlot.h"

class FoodManager
{
private:
	std::vector<Food> m_foods;
	std::vector<BentoSlot> m_slots;

	// 現在つかんでいるFood
	Food* m_heldFood = nullptr;

	// 最後に獲得したスコア
	int m_lastGain = 0;

public:
	// おかずリストをセット
	void SetFoods(const std::vector<Food>& foods);
	Food& AddFood(const Food& f);

	// 空きスペーススロットをセット
	void SetSlots(const std::vector<BentoSlot>& slots);

	// つかんでいるか
	bool IsAnyFoodHold()const;

	// つかむ
	void HoldFood(Food& f);

	// 重なり判定
	int JudgeFood(const Food& f);
	
	void Update();
	void Draw();

	// 設置済み(固定された)おかずの数
	int GetLockedCount()const;

	// 最後に獲得したスコア
	int PopLastGain();
};