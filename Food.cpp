#include "Food.h"
#include "Input.h"
#include "DxLib.h"
#include "math.h"

Food::Food(int x, int y) :
	m_foodPos(x, y),
	m_isHold(false),
	m_isLocked(false),
	m_angle(0)
{

}

void Food::AddBoxPart(const BoxPart& part)
{
	m_parts.push_back(part);
}

void Food::SetHold()
{
	m_isHold = true;
}

// 回転
void Food::Rotate()
{
	m_angle = (m_angle - 90) % 360;
}

bool Food::IsLocked() const
{
	return m_isLocked;
}

// 座標の回転
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

void Food::Update()
{
	// おかずの移動
	if (m_isHold)
	{
		m_foodPos = Input::GetPoint();

		// スペースでおかずを離す
		if (Input::IsSpaceDown())
		{
			m_isHold = false;
			m_isLocked = true;
		}
	}
}

void Food::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);

	int color = GetColor(0, 255, 0);
	if (m_isLocked) color = GetColor(255, 0, 0);
	else if (m_isHold) color = GetColor(0, 0, 255);

	for (auto& p : m_parts)
	{
		Vec2 local[4] =
		{

			Vec2(p.offsetX - p.width / 2,p.offsetY - p.height / 2),
			Vec2(p.offsetX + p.width / 2,p.offsetY - p.height / 2),
			Vec2(p.offsetX + p.width / 2,p.offsetY + p.height / 2),
			Vec2(p.offsetX - p.width / 2,p.offsetY + p.height / 2),
		};

		for (int i = 0; i < 4; i++)
		{
			local[i] = RotatePoint(local[i], m_angle);
			local[i] = local[i] + m_foodPos;
		}

		// 四角形描画
		DrawQuadrangle(
			(int)local[0].x, (int)local[0].y,
			(int)local[1].x, (int)local[1].y,
			(int)local[2].x, (int)local[2].y,
			(int)local[3].x, (int)local[3].y,
			color, true
		);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}