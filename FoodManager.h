#pragma once
#include <vector>
#include "Food.h"

class FoodManager
{
private:
	std::vector<Food> m_foods;

	// åªç›Ç¬Ç©ÇÒÇ≈Ç¢ÇÈFood
	Food* m_heldFood = nullptr;

public:
	void SetFoods(const std::vector<Food>& foods);
	Food& AddFood(const Food& f);

	bool IsAnyFoodHold()const;
	void HoldFood(Food& f);

	void Update();
	void Draw();

};