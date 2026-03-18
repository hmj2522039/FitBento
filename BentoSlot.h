#pragma once
#include "Food.h"
#include "Vector2.h"
#include "DxLib.h"

struct BentoSlot
{
    Vec2 pos;      // ’†SÀ•W

    std::vector<BoxPart> parts;

    void Draw() const;
};
