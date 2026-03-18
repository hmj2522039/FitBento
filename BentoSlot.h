#pragma once
#include "Food.h"
#include "Vector2.h"
#include "DxLib.h"
#include <string>

struct BentoSlot
{
    Vec2 pos;      // 中心座標

    std::vector<BoxPart> parts;

    std::string tag;    // タグ

    void Draw() const;
};
