#include "LunchBox.h"

LunchBox::LunchBox(int graph, Vec2 pos)
    : m_graph(graph), m_pos(pos)
{
}

void LunchBox::SetSlots(const std::vector<BentoSlot>& slots)
{
    m_slots = slots;
}

const std::vector<BentoSlot>& LunchBox::GetSlots() const
{
    return m_slots;
}

void LunchBox::Draw()
{
    // •Ù“–” ‰æ‘œ•`‰æ
    DrawGraph((int)m_pos.x, (int)m_pos.y, m_graph, true);

    // ‹ó‚«ƒXƒƒbƒg•`‰æ
    for (auto& s : m_slots)
    {
        s.Draw();
    }
}
