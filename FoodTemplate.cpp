#include "FoodTemplate.h"

Food FoodTemplate::CreateFoodAt(float x, float y)const
{
	Food f(x, y);
	for (auto& p : parts)
		f.AddBoxPart(p);
	return f;
}