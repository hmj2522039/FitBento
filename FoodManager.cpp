#include "Food.h"
#include "FoodManager.h"
#include "Input.h"

void FoodManager::SetFoods(const std::vector<Food>& foods)
{
	m_foods = foods;
}

void FoodManager::AddFood(const Food& f)
{
	m_foods.push_back(f);
}

void FoodManager::Update()
{
	if (Input::IsMouseDown(Left))
	{
		// d‚È‚Á‚Ä‚¢‚éã‚Ì‚¨‚©‚¸‚©‚ç”»’è‚ğs‚¤
		for (int i = m_foods.size() - 1; i >= 0; i--)
		{
			// Šù‚ÉˆÚ“®Ï‚İ‚È‚ç‚Â‚©‚ß‚È‚¢
			if (m_foods[i].IsLocked())
			{
				continue;
			}

			if (m_foods[i].CheckHold())
			{
				m_foods[i].SetHold();
				break;
			}
		}
	}

	for (auto& f : m_foods)
	{
		f.Update();
	}
}

void FoodManager::Draw()
{
	for (auto& f : m_foods)
	{
		f.Draw();
	}
}