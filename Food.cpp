#include "Food.h"
#include "Input.h"
#include "DxLib.h"
#include "math.h"

Food::Food(int x, int y, int w, int h, float range) :
	m_foodX(x), m_foodY(y),
	m_foodW(w),	m_foodH(h),
	m_rectRange(range),
	m_isHold(false),
	m_isLocked(false)
{

}

bool Food::CheckHold() const
{
	float dx = Input::m_mouseX - m_foodX;
	float dy = Input::m_mouseY - m_foodY;
	float mouseDistance = dx * dx + dy * dy;
	float range = m_rectRange * m_rectRange;

	return mouseDistance < range;
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
	int color = GetColor(0, 255, 0);
	if (m_isLocked) color = GetColor(255, 0, 0);
	else if (m_isHold) color = GetColor(0, 0, 255);

	DrawBox(
		m_foodX - m_foodW / 2, m_foodY - m_foodH / 2,
		m_foodX + m_foodW / 2, m_foodY + m_foodH / 2,
		color,
		true
	);
}