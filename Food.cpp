#include "Food.h"
#include "DxLib.h"
#include "math.h"

Food::Food(int x, int y, int w, int h, float range) :
	m_foodX(x),
	m_foodY(y),
	m_foodW(w),
	m_foodH(h),
	m_rectRange(range),
	m_mouseX(),
	m_mouseY(),
	m_clicked(0),
	m_isHold(false)
{

}


void Food::Update()
{

	// マウスでおかずをつかむ
	GetMousePoint(&m_mouseX, &m_mouseY);

	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		// マウスとおかず中心の距離の差
		float dx = m_mouseX - m_foodX;
		float dy = m_mouseY - m_foodY;
		float mouseDistance = sqrtf(dx * dx + dy * dy);
		if (m_clicked == 0)
		{
			if (mouseDistance < m_rectRange)
			{
				m_isHold = true;
			}
			else
			{
				m_isHold = false;
			}
		}
	}
	m_clicked = GetMouseInput() & MOUSE_INPUT_LEFT;
	
	if (m_isHold)
	{
		m_foodX = m_mouseX;
		m_foodY = m_mouseY;
	}

	// スペースでおかずを離す
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_isHold = false;
	}
}

void Food::Draw()
{
	DrawBox(
		m_foodX - m_foodW / 2, m_foodY - m_foodH / 2,
		m_foodX + m_foodW / 2, m_foodY + m_foodH / 2,
		GetColor(255, 0, 0),
		true
	);
}