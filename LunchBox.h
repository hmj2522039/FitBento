#pragma once
#include "DxLib.h"
#include "Vector2.h"
#include "BentoSlot.h"
#include <vector>

class LunchBox
{
private:
    int m_graph;    // 弁当箱画像
    Vec2 m_pos;     // 表示位置
    std::vector<BentoSlot> m_slots;  // 空スロット

public:
    LunchBox(int graph, Vec2 pos);

    void SetSlots(const std::vector<BentoSlot>& slots);
    const std::vector<BentoSlot>& GetSlots() const;

    void Draw();
};
