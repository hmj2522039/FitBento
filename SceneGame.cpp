#include "SceneGame.h"
#include "FoodPreset.h"
#include "FoodManager.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"

void SceneGame::Initialize()
{
	m_fontHandle = CreateFontToHandle("HGP‘n‰pŠpƒSƒVƒbƒNUB", 52, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	auto templates = FoodPreset::CreateFoodTemplates();
	m_foodList.SetTemplates(templates);

	m_foodManager.SetFoods({});
}

void SceneGame::Finalize()
{
	DeleteFontToHandle(m_fontHandle);
}

void SceneGame::Update()
{
	m_foodList.Update();

	Food newFood(0, 0);
	if (m_foodList.CheckClick(newFood))
	{
		m_foodManager.AddFood(newFood);
	}

	m_foodManager.Update();
}

void SceneGame::Draw()
{
	// ”wŒi
	DrawBoxAA(0, 0, Screen::Width, Screen::Height, GetColor(246, 255, 194), true);

	// •Ù“–” 
	m_lunchBox.Draw();

	// ‚¨‚©‚¸ƒŠƒXƒg‘¤”wŒi
	DrawBoxAA(Screen::Width - 520, 0, Screen::Width, Screen::Height, GetColor(246, 243, 194), true);

	// ‚¨‚©‚¸‚Ì•`‰æ
	m_foodManager.Draw();

	// ‚¨‚©‚¸ƒŠƒXƒg‚ğ•`‰æ
	m_foodList.Draw();

	// c‚è•b”•\¦
	DrawRoundRect(15, 15, 480, 120, 20, 20, GetColor(252, 246, 150), true);
	DrawStringToHandle(43, 40, "c‚èŠÔ:@@•b", GetColor(255, 137, 72), m_fontHandle, GetColor(150, 40, 0));
}