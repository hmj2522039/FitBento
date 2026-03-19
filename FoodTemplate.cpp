#include "FoodTemplate.h"
#include "DxLib.h"

Food FoodTemplate::CreateFoodAt(float x, float y)const
{
	Food f(x, y);
	for (auto& p : parts)
	{
		f.AddBoxPart(p);
	}

	f.SetTag(tag);

	if (!imagePath.empty())
	{
		int g = LoadGraph(imagePath.c_str());
		f.SetGraph(g);
	}

	return f;
}