#pragma once
#include <vector>
#include "Food.h"

class FoodManager
{
private:
	std::vector<Food> m_foods;

public:
	void SetFoods(const std::vector<Food>& foods);

	void Update();
	void Draw();

};