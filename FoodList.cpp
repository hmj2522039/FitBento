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
	Vec2 mouse = Input::GetPoint();
	if (mouse.x >= Screen::Width - 520 && mouse.x <= Screen::Width &&
		mouse.y >= Screen::Top && mouse.y <= Screen::Height)

	m_scroll += Input::GetWheel() * 30;

	// リストの高さ
	int listHeight = m_templates.size() * layout.m_listFoodHeight;

	// 表示範囲
	int viewHeight = Screen::Height - layout.m_marginTopBottom;

	// スクロールの最大値
	m_scrollMax = listHeight - viewHeight;
	if (m_scrollMax < 0) m_scrollMax = 0;

	// スクロールの範囲を制限
	if (m_scroll > 0) m_scroll = 0;
	if (m_scroll < -m_scrollMax) m_scroll = -m_scrollMax;
}

void FoodList::Draw()
{
	int baseX = layout.m_baseX;
	int baseY = layout.m_baseY + m_scroll;

	for (int i = 0; i < m_templates.size(); i++)
	{
		int y = baseY + i * layout.m_listFoodHeight;

		// おかずを描画
		Food temp = m_templates[i].CreateFoodAt(baseX + layout.m_foodOffsetX, y + layout.m_foodOffsetY);
		temp.Draw();

		// おかずの名前
		DrawString(baseX + layout.m_nameOffsetX, y + layout.m_nameOffsetY, m_templates[i].name, GetColor(50, 50, 50));

		// 枠
		DrawBox(baseX, y, baseX + layout.m_listFoodWidth, y + layout.m_listFoodHeight, GetColor(255, 200, 0),false); 
	}

	// スクロールバー
	int barX = layout.m_barX;
	int barY = layout.m_barTop;
	int barWidth = layout.m_barWidth;
	int barHeight = Screen::Height - layout.m_marginTopBottom;

	// バーの背景
	DrawBox(barX, barY, barX + barWidth, barY + barHeight, GetColor(200, 200, 200), true);

	// おかずリスト全体の高さ
	int listHeight = m_templates.size() * layout.m_listFoodHeight;

	// 表示範囲
	int viewHeight = Screen::Height - layout.m_marginTopBottom;

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
	int baseX = layout.m_baseX;
	int baseY = layout.m_baseY + m_scroll;

	for (int i = 0; i < m_templates.size(); i++)
	{
		int y = baseY + i * layout.m_listFoodHeight;

		if (mouse.x >= baseX && mouse.x <= baseX + layout.m_listFoodWidth && 
			mouse.y >= y	 && mouse.y <= y	 + layout.m_listFoodHeight)
		{
			// おかずをつかむ（マウス座標に追従するおかずを追加）
			if (Input::IsMouseDown(Left))
			{
				food = m_templates[i].CreateFoodAt(mouse.x, mouse.y);
				return true;
			}
		}
	}
	return false;
}