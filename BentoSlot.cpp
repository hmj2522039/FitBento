#include "BentoSlot.h"
#include "DxLib.h"

void BentoSlot::Draw() const
{
    int color = GetColor(255, 150, 0);

    for (auto& p : parts)
    {
        int left = (int)(pos.x + p.offsetX - p.width / 2);
        int right = (int)(pos.x + p.offsetX + p.width / 2);
        int top = (int)(pos.y + p.offsetY - p.height / 2);
        int bottom = (int)(pos.y + p.offsetY + p.height / 2);

        DrawBox(left, top, right, bottom, color, false); // ògê¸
    }
}