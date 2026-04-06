#pragma once
#include "Food.h"
#include <vector>
#include <string>

struct FoodTemplate
{
	const char* name;
	std::string tag;
	std::string imagePath;
	std::vector<BoxPart>parts;

	int m_graph = -1;

	Food CreateFoodAt(float x, float y)const;
};