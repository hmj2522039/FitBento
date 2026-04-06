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

	if (m_graph != -1)
	{
		f.SetGraph(m_graph);
	}

	return f;
}