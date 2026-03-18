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
	// 右クリックでおかずを回転させる
	if (Input::IsMouseDown(Right) && m_heldFood)
	{
		m_heldFood->Rotate();
	}

	for (auto& f : m_foods)
	{
		f.Update();

		// つかみ状態を解除
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