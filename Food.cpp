#include "Food.h"
#include "Input.h"
#include "DxLib.h"
#include "math.h"

Food::Food(int x, int y) :
	m_foodX(x), m_foodY(y),
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

bool Food::CheckHold() const
{
	for (auto& p : m_parts)
	{
		int x1 = m_foodX + p.offsetX - p.width	/ 2;
		int y1 = m_foodY + p.offsetY - p.height	/ 2;
		int x2 = m_foodX + p.offsetX + p.width	/ 2;
		int y2 = m_foodY + p.offsetY + p.height	/ 2;

		if (Input::m_mouseX >= x1 && Input::m_mouseX <= x2 &&
			Input::m_mouseY >= y1 && Input::m_mouseY <= y2)
		{
			return true;
		}
	}
	return false;
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
		m_foodX = Input::m_mouseX;
		m_foodY = Input::m_mouseY;

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
		int x1 = m_foodX + p.offsetX - p.width	/ 2;
		int y1 = m_foodY + p.offsetY - p.height	/ 2;
		int x2 = m_foodX + p.offsetX + p.width	/ 2;
		int y2 = m_foodY + p.offsetY + p.height	/ 2;
		
		DrawBox(x1, y1, x2, y2, color, true);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}