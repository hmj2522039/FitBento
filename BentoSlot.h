#pragma once
#include "Vector2.h"
#include "DxLib.h"

struct BentoSlot
{
    Vec2 pos;      // íÜêSç¿ïW
    int width;
    int height;
    int correctAngle; // 0, 90, 180, 270

    void Draw() const
    {
        Vec2 p1 = pos + Vec2(-width / 2, -height / 2);
        Vec2 p2 = pos + Vec2(width / 2, height / 2);
        DrawBox((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, GetColor(255, 200, 200), false);
    }
};
