#include "Food.h"
#include "FoodPreset.h"

std::vector<Food> FoodPreset::CreateInitFoods()
{
	std::vector<Food> foods;

	// Ç±ÇÃâ∫Ç…ê∂ê¨Ç∑ÇÈÇ®Ç©Ç∏ÇãLèq
	Food test(200, 400);
	test.AddBoxPart({-50, 0, 50, 150}); // èc
	test.AddBoxPart({0, -50, 150, 50}); // â°
	foods.push_back(test);

	Food test2(400, 400);
	test2.AddBoxPart({ 50,0,50,150 });
	test2.AddBoxPart({ 0,50,150,50 });
	foods.push_back(test2);

	return foods;
}