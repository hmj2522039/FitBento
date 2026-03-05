#pragma once

struct Vector2
{
	float x;
	float y;

	constexpr Vector2():
		x(0),
		y(0){}

	template<typename T1, typename T2>
	constexpr Vector2(T1 x, T2 y) :
		x(static_cast<float>(x)),
		y(static_cast<float>(y)) {}

	// 加算
	constexpr Vector2 operator + (const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	constexpr Vector2& operator += (const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	// 減算


	// 長さ

	// 長さの２乗

	// 角度からベクトル

	// ベクトルから角度

};