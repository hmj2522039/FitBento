#include "FoodList.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"

void FoodList::SetTemplates(const std::vector<FoodTemplate>& t)
{
	m_templates = t;
}

void FoodList::Update()
{
	// ホイールスクロール
	m_scroll += Input::GetWheel() * 30;

	// おかずの高さ
	const int okazuHeight = 200;

	// リストの高さ
	int listHeight = m_templates.size() * okazuHeight;

	// 表示範囲
	int viewHeight = Screen::Height - 100;

	// スクロールの最大値がマイナスにならないようにする
	m_scrollMax = listHeight - viewHeight;
	if (m_scrollMax < 0) m_scrollMax = 0;

	// スクロールの範囲を制限
	if (m_scroll > 0) m_scroll = 0;
	if (m_scroll < -m_scrollMax) m_scroll = -m_scrollMax;
}

void FoodList::Draw()
{
	int baseX = 1470;
	int baseY = 50 + m_scroll;

	for (int i = 0; i < m_templates.size(); i++)
	{
		int y = baseY + i * 200;

		// おかずを描画
		Food temp = m_templates[i].CreateFoodAt(baseX + 240, y + 90);
		temp.Draw();

		// おかずの名前
		DrawString(baseX + 20, y + 140, m_templates[i].name, GetColor(50, 50, 50));

		DrawBox(baseX, y, baseX + 350, y + 200, GetColor(255, 200, 0),false); 
	}

	// スクロールバー
	int barX = 1900;
	int barY = 50;
	int barWidth = 10;
	int barHeight = Screen::Height - 100;

	// バーの背景
	DrawBox(barX, barY, barX + barWidth, barY + barHeight, GetColor(200, 200, 200), true);

	// おかずリスト全体の高さ
	int listHeight = m_templates.size() * 200;

	// 表示範囲
	int viewHeight = Screen::Height - 100;

	// つまみの高さ
	int thumbHeight = (int)((float)viewHeight / listHeight * barHeight);
	if (thumbHeight < 20) thumbHeight = 20;

	// つまみの位置
	int thumbY = barY; 
	if (m_scrollMax > 0)
	{
		float rate = -(float)m_scroll / m_scrollMax;	// 表示している範囲÷リスト全体の高さ
		thumbY = barY + (int)(rate * (barHeight - thumbHeight));
	}

	// つまみの描画
	DrawBox(barX, thumbY, barX + barWidth, thumbY + thumbHeight, GetColor(120, 120, 120), true);

}

bool FoodList::CheckClick(Food& food)
{
	Vec2 mouse = Input::GetPoint();
	int baseX = 1470;
	int baseY = 50 + m_scroll;

	for (int i = 0; i < m_templates.size(); i++)
	{
		int y = baseY + i * 200;


		if (mouse.x >= baseX && mouse.x <= baseX + 350 && mouse.y >= y && mouse.y <= y + 180)
		{
			if (Input::IsMouseDown(Left))
			{
				food = m_templates[i].CreateFoodAt(mouse.x, mouse.y);
				food.SetHold();
				return true;
			}
		}
	}
	return false;
}