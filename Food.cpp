#include "Food.h"
#include "Input.h"
#include "DxLib.h"
#include "math.h"

Food::Food(int x, int y) :
	m_foodPos(x, y),
	m_isHold(false),
	m_isLocked(false)
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

bool Food::IsLocked() const
{
	return m_isLocked;
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
		Vec2 p1 = m_foodPos + Vec2(p.offsetX - p.width / 2, p.offsetY - p.height / 2);
		Vec2 p2 = m_foodPos + Vec2(p.offsetX + p.width / 2, p.offsetY + p.height / 2);
		
		DrawBox((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, color, true);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}