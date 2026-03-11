#pragma once
#include "Food.h"
#include "FoodTemplate.h"
#include <vector>

class FoodList
{
private:
	std::vector<FoodTemplate> m_templates;
	
	int m_scroll = 0;
	int m_scrollMax = 0;	// ƒXƒNƒ[ƒ‹‚ÌÅ‘å—Ê
	
public:
	void SetTemplates(const std::vector<FoodTemplate>& t);
	
	void Update();
	void Draw();

	bool CheckClick(Food& food);
};