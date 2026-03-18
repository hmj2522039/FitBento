#pragma once
#include "Food.h"
#include <vector>
#include <string>

struct FoodTemplate
{
	const char* name;
	std::string tag;
	std::vector<BoxPart>parts;

	Food CreateFoodAt(float x, float y)const;
};