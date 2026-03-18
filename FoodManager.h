#pragma once
#include <vector>
#include "Food.h"
#include "BentoSlot.h"

class FoodManager
{
private:
	std::vector<Food> m_foods;
	std::vector<BentoSlot> m_slots;

	// åªç›Ç¬Ç©ÇÒÇ≈Ç¢ÇÈFood
	Food* m_heldFood = nullptr;

	int m_lastGain = 0;

public:
	void SetFoods(const std::vector<Food>& foods);
	Food& AddFood(const Food& f);

	void SetSlots(const std::vector<BentoSlot>& slots);

	bool IsAnyFoodHold()const;
	void HoldFood(Food& f);

	int JudgeFood(const Food& f);
	
	void Update();
	void Draw();

	int GetLockedCount()const;
	int PopLastGain();

};