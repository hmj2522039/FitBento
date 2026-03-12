#pragma once
#include "Food.h"
#include "FoodTemplate.h"
#include <vector>

struct FoodListLayout
{
	// リストの範囲
	int m_baseX = 1470;
	int m_baseY = 50;

	// リストにあるおかずの範囲
	int m_listFoodWidth = 350;
	int m_listFoodHeight = 200;

	// 名前表示のオフセット
	int m_nameOffsetX = 20;
	int m_nameOffsetY = 140;

	// 項目ごとのおかずのオフセット
	int m_foodOffsetX = 240;
	int m_foodOffsetY = 90;

	// 上下の余白
	int m_marginTopBottom = 100;

	// スクロールバー
	int m_barX = 1900;
	int m_barWidth = 10;
	int m_barTop = 50;
};

class FoodList
{
private:
	std::vector<FoodTemplate> m_templates;
	FoodListLayout layout;
	
	int m_scroll = 0;
	int m_scrollMax = 0;	// スクロールの最大量
	
public:
	void SetTemplates(const std::vector<FoodTemplate>& t);
	
	void Update();
	void Draw();

	bool CheckClick(Food& food);
};