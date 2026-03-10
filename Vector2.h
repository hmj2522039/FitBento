#pragma once
#include <cmath>
#include <cassert>

struct Vec2
{
	static constexpr double Pi = 3.141592653589793;

	float x;
	float y;

	constexpr Vec2() :
		x(0),
		y(0) {}

	template<typename T1, typename T2>	// ”CˆÓ‚ÌŒ^‚Ìx,y‚ğó‚¯æ‚ê‚é‚æ‚¤‚É‚·‚é
	constexpr Vec2(T1 x, T2 y) :
		// float‚É•ÏŠ·
		x(static_cast<float>(x)),
		y(static_cast<float>(y)) {}

	// ‰ÁZ
	constexpr Vec2 operator + (const Vec2& other) const
	{
		return Vec2(x + other.x, y + other.y);
	}

	constexpr Vec2& operator += (const Vec2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	// Œ¸Z
	constexpr Vec2 operator - (const Vec2& other) const
	{
		return Vec2(x - other.x, y - other.y);
	}

	constexpr Vec2& operator -= (const Vec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	// æZ
	constexpr Vec2 operator* (const float& scalar)const
	{
		return Vec2(x * scalar, y * scalar);
	}
	constexpr friend Vec2 operator*(const float& scalar, const Vec2& v)
	{
		return v * scalar;
	}
	constexpr Vec2& operator*=(const float& scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	// œZ
	constexpr Vec2 operator/(const float& scalar) const
	{
		return Vec2(x / scalar, y / scalar);
	}
	constexpr Vec2& operator/=(const float& scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

	// “™‰¿
	constexpr bool operator==(const Vec2& other) const
	{
		return (x == other.x) && (y == other.y);
	}

	// ”ñ“™‰¿
	constexpr bool operator!=(const Vec2& other) const
	{
		return !(*this == other);
	}

	// ‹tƒxƒNƒgƒ‹
	constexpr Vec2 operator-() const
	{
		return Vec2(-x, -y);
	}


	// “àÏ
	static constexpr float Dot(const Vec2& v1, const Vec2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	// ŠOÏ
	static constexpr float Cross(const Vec2& v1, const Vec2& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}

	// ’·‚³‚Ì‚Qæ
	constexpr float SqrMagnitude() const
	{
		return Dot(*this, *this);
	}

	// ’·‚³
	float Magnitude() const
	{
		return std::sqrtf(SqrMagnitude());
	}

	Vec2 Normalized() const
	{
		float m = Magnitude();
		assert(m != 0 && "0œZ");
		return *this / m;
	}
	const Vec2& Normalize()
	{
		*this = Normalized();
		return *this;
	}

	// Šp“x‚©‚çƒxƒNƒgƒ‹
	static constexpr Vec2 AngleToDirect(double deg)
	{
		double rad = deg * (Pi / 180.0);
		return Vec2(std::cos(rad), std::sin(rad));
	}

	// ƒxƒNƒgƒ‹‚©‚çŠp“x
	float ToRad() const
	{
		return std::atan2(y, x);
	}

	float ToDeg()const
	{
		return ToRad() * (180.0f / Pi);
	}
};