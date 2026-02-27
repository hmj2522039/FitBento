#include "Mouse.h"

void Mouse::Update()
{
	GetMousePoint(&m_mouseX, &m_mouseY);

	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		if (m_bx < m_mouseX && m_by < m_mouseY && m_bx + m_size > m_mouseX && m_by + m_size > m_mouseY)
		{
			if (m_clicked == 0)
			m_isHold = !m_isHold;
		}
	}
	m_clicked = GetMouseInput() & MOUSE_INPUT_LEFT;
}

void Mouse::Draw()
{
	DrawBox(m_bx, m_by, m_bx + m_size, m_by + m_size, GetColor(255, 0, 0), true);

	if (m_isHold)
	{
		DrawFormatString(500, 500, GetColor(255, 255, 255), "a");
	}
}