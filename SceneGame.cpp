#include "SceneGame.h"
#include "FoodPreset.h"
#include "FoodManager.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"

void SceneGame::Initialize()
{
	m_fontHandle = CreateFontToHandle("HGPënâpäpÉSÉVÉbÉNUB", 52, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	auto templates = FoodPreset::CreateFoodTemplates();
	m_foodList.SetTemplates(templates);

	m_lunchBox.Initialize();

	m_foodManager.SetFoods({});
}

void SceneGame::Finalize()
{
	DeleteFontToHandle(m_fontHandle);
}

void SceneGame::Update()
{
	m_foodList.Update();

	if (!m_foodManager.IsAnyFoodHold())
	{
		Food newFood(0, 0);
		if (m_foodList.CheckClick(newFood))
		{
			Food& added = m_foodManager.AddFood(newFood);
			m_foodManager.HoldFood(added);
		}
	}

	m_foodManager.Update();
}

void SceneGame::Draw()
{
	//// îwåi
	DrawBoxAA(0, 0, Screen::Width, Screen::Height, GetColor(246, 255, 194), true);

	//// ïŸìñî†
	m_lunchBox.Draw();

	//// Ç®Ç©Ç∏ÉäÉXÉgë§îwåi
	DrawBoxAA(Screen::Width - 520, 0, Screen::Width, Screen::Height, GetColor(246, 243, 194), true);

	////// Ç®Ç©Ç∏ÉäÉXÉgÇï`âÊ
	m_foodList.Draw();

	////// Ç®Ç©Ç∏ÇÃï`âÊ
	m_foodManager.Draw();

	////// écÇËïbêîï\é¶
	DrawRoundRect(15, 15, 480, 120, 20, 20, GetColor(252, 246, 150), true);
	DrawStringToHandle(43, 40, "écÇËéûä‘:Å@Å@ïb", GetColor(255, 137, 72), m_fontHandle, GetColor(150, 40, 0));
}