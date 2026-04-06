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

// ‰ñ“]
void Food::Rotate()
{
	m_angle = (m_angle - 90) % 360;
}

bool Food::IsLocked() const
{
	return m_isLocked;
}

// À•W‚Ì‰ñ“]
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
	// ‚¨‚©‚¸‚ÌˆÚ“®
	if (m_isHold)
	{
		m_foodPos = Input::GetPoint();

		// ƒXƒy[ƒX‚Å‚¨‚©‚¸‚ğ—£‚·
		if (Input::IsSpaceDown())
		{
			m_isHold = false;
			m_isLocked = true;
		}
	}
}

void Food::Draw()
{
	// ‰æ‘œ‚ª‚ ‚éê‡‚Í‰æ‘œ‚ğ•`‰æ
	if (m_graph != -1)
	{
		DrawRotaGraph(
			(int)m_foodPos.x,
			(int)m_foodPos.y,
			1.0,
			-m_angle * 3.141592653589793f / 180.0f,
			m_graph,
			true
		);
	}

#ifdef _DEBUG_
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

		// lŠpŒ`•`‰æ
		DrawQuadrangle(
			(int)local[0].x, (int)local[0].y,
			(int)local[1].x, (int)local[1].y,
			(int)local[2].x, (int)local[2].y,
			(int)local[3].x, (int)local[3].y,
			color, false
		);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
#endif
}