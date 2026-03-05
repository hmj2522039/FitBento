#include "FoodPreset.h"

std::vector<Food> FoodPreset::CreateInitFoods()
{
	std::vector<Food> foods;

	// Ç±ÇÃâ∫Ç…ê∂ê¨Ç∑ÇÈÇ®Ç©Ç∏ÇãLèq
	foods.emplace_back(200, 200, 80, 80, 50.0f);
	foods.emplace_back(200, 400, 80, 80, 50.0f);
	foods.emplace_back(200, 600, 80, 80, 50.0f);


	return foods;
}