#pragma once
#include "Vector2.h"

namespace Screen
{
	static constexpr int Width	= 1920;	// 幅
	static constexpr int Height = 1080;	// 高さ
	static constexpr Vec2 Size	= Vec2(Width, Height);	// 幅、高さ

	static constexpr Vec2 Center	= Size / 2;	// 中央
	static constexpr int  Top		= 0;		// 上端
	static constexpr int  Bottom	= Height;	// 下端
	static constexpr int  Left		= 0;		// 左端
	static constexpr int  Right		= Width;	// 右端

	static constexpr Vec2 TopCenter	= Vec2(Center.x, Top);	// 中央上
	static constexpr Vec2 TopLeft	= Vec2(Left, Top);		// 左上
	static constexpr Vec2 TopRight	= Vec2(Right, Top);		// 右上

	static constexpr Vec2 CenterLeft	= Vec2(Left,Center.y);		// 中央左
	static constexpr Vec2 CenterRight	= Vec2(Right, Center.y);	// 中央右

	static constexpr Vec2 BottomCenter	= Vec2(Center.x, Bottom);
	static constexpr Vec2 BottomLeft	= Vec2(Left, Bottom);
	static constexpr Vec2 BottomRight	= Vec2(Right, Bottom);
}