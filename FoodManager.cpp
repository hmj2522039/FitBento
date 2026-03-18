#include "Food.h"
#include "FoodManager.h"
#include "Input.h"
#include "DxLib.h"
#include <math.h>

void FoodManager::SetFoods(const std::vector<Food>& foods)
{
	m_foods = foods;
}

Food& FoodManager::AddFood(const Food& f)
{
	m_foods.push_back(f);
	return m_foods.back();
}

void FoodManager::SetSlots(const std::vector<BentoSlot>& slots)
{
	m_slots = slots;
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

int FoodManager::JudgeFood(const Food& f)
{
    if (m_slots.empty()) return 0;

    const BentoSlot* best = nullptr;
    float bestDist = 999999;

    // 最も近いスロットを探す
    for (auto& s : m_slots)
    {
        float dx = f.GetPos().x - s.pos.x;
        float dy = f.GetPos().y - s.pos.y;
        float dist = sqrt(dx * dx + dy * dy);

        if (dist < bestDist)
        {
            bestDist = dist;
            best = &s;
        }
    }

    if (!best) return 0;

    // 位置ズレ
    float dx = f.GetPos().x - best->pos.x;
    float dy = f.GetPos().y - best->pos.y;
    float dist = sqrt(dx * dx + dy * dy);

    int posScore = 50 - (int)(dist * 0.5f);
    if (posScore < 0) posScore = 0;

    // 角度ズレ（正方形は角度のずれを判定しない）
    int angleScore = 0;
    if (best->width == best->height)
    {
        angleScore = 50;
    }
    else
    {
        int angleDiff = abs(f.GetAngle() - best->correctAngle);
        angleDiff %= 360;
        if (angleDiff > 180) angleDiff = 360 - angleDiff;

        angleScore = 50 - angleDiff;
        if (angleScore < 0) angleScore = 0;
    }

    return posScore + angleScore;
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
        bool wasLocked = f.IsLocked();

        f.Update();

        // ロックされた瞬間に判定
        if (!wasLocked && f.IsLocked())
        {
            int score = JudgeFood(f);
            m_lastGain = score;

            m_heldFood = nullptr;
        }

        // つかみ解除
        if (f.IsLocked() && m_heldFood == &f)
        {
            m_heldFood = nullptr;
        }
    }
}

void FoodManager::Draw()
{
    // スロット描画
    for (auto& s : m_slots)
    {
        s.Draw();
    }

	for (auto& f : m_foods)
	{
		f.Draw();
	}
}

int FoodManager::GetLockedCount()const
{
    int count = 0;
    for (auto& f : m_foods)
    {
        if (f.IsLocked()) count++;
    }
    return count;
}

int FoodManager::PopLastGain()
{
    int g = m_lastGain;
    m_lastGain = 0;
    return g;
}