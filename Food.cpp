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

void Food::Update()
{
	GetMousePoint(&m_mouseX, &m_mouseY);
	
	// おかずをつかむ
	if(Input::IsMouseDown(Left) && !m_isLocked)
	{
		// マウスポインタとおかず中心の距離の差
		float dx = m_mouseX - m_foodX;
		float dy = m_mouseY - m_foodY;
		float mouseDistance = dx * dx + dy * dy;
		float range = m_rectRange * m_rectRange;

		if (mouseDistance < range)
		{
			m_isHold = true;
		}
	}
	
	// おかずの移動
	if (m_isHold)
	{
		m_foodX = m_mouseX;
		m_foodY = m_mouseY;

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