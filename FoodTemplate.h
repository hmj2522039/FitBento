#pragma once
#include "Food.h"
#include <vector>

struct FoodTemplate
{
	const char* name;
	std::vector<BoxPart>parts;

	Food CreateFoodAt(float x, float y)const;
};