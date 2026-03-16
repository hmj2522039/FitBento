#include "Food.h"
#include "FoodManager.h"
#include "Input.h"

void FoodManager::SetFoods(const std::vector<Food>& foods)
{
	m_foods = foods;
}

Food& FoodManager::AddFood(const Food& f)
{
	m_foods.push_back(f);
	return m_foods.back();
}

bool FoodManager::IsAnyFoodHold()const
{
	return m_heldFood != nullptr;
}

void FoodManager::HoldFood(Food& f)
{
	f.SetHold();
	m_heldFood = &f;
}

void FoodManager::Update()
{
	for (auto& f : m_foods)
	{
		f.Update();

		// Ç¬Ç©Ç›èÛë‘Çâèú
		if (f.IsLocked() && m_heldFood == &f)
		{
			m_heldFood = nullptr;
		}
	}
}

void FoodManager::Draw()
{
	for (auto& f : m_foods)
	{
		f.Draw();
	}
}