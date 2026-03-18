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

static Vec2 RotatePoint(const Vec2& p, int angle)
{
    float rad = angle * 3.141592653589793f / 180.0f;
    float cosA = cosf(rad);
    float sinA = sinf(rad);

    return Vec2(
        p.x * cosA + p.y * sinA,
        -p.x * sinA + p.y * cosA
    );
}

// 重なっている面積
static int CalcOverlapArea(
    int A_left, int A_top, int A_right, int A_bottom,
    int B_left, int B_top, int B_right, int B_bottom)
{
    int overlapW = max(0, min(A_right, B_right) - max(A_left, B_left));
    int overlapH = max(0, min(A_bottom, B_bottom) - max(A_top, B_top));
    return overlapW * overlapH;
}


int FoodManager::JudgeFood(const Food& f)
{
    if (m_slots.empty()) return 0;

    // 最も近いスロットを探す
    const BentoSlot* best = nullptr;
    float bestDist = 999999;

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

    int totalArea = 0;

    for (auto& fp : f.GetParts())
    {
        Vec2 p(fp.offsetX, fp.offsetY);
        p = RotatePoint(p, f.GetAngle());
        p = p + f.GetPos();

        int f_left = (int)(p.x - fp.width / 2);
        int f_right = (int)(p.x + fp.width / 2);
        int f_top = (int)(p.y - fp.height / 2);
        int f_bottom = (int)(p.y + fp.height / 2);

        for (auto& sp : best->parts)
        {
            int s_left = (int)(best->pos.x + sp.offsetX - sp.width / 2);
            int s_right = (int)(best->pos.x + sp.offsetX + sp.width / 2);
            int s_top = (int)(best->pos.y + sp.offsetY - sp.height / 2);
            int s_bottom = (int)(best->pos.y + sp.offsetY + sp.height / 2);

            // 重なり面積を加算
            totalArea += CalcOverlapArea(
                f_left, f_top, f_right, f_bottom,
                s_left, s_top, s_right, s_bottom
            );
        }
    }

    // スコア化
    int score = totalArea / 100; // 面積100で1点
    if (score < 0) score = 0;

    return score;
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