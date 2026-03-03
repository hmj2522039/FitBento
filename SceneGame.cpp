#include "SceneGame.h"
#include "Food.h"
#include "Screen.h"
#include "DxLib.h"

void SceneGame::Initialize()
{
	m_fontHandle = CreateFontToHandle("HGPënâpäpÉSÉVÉbÉNUB", 52, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

void SceneGame::Finalize()
{
	DeleteFontToHandle(m_fontHandle);
}

void SceneGame::Update()
{
	food.Update();
}

void SceneGame::Draw()
{
	DrawBoxAA(0, 0, Screen::Width, Screen::Height, GetColor(246, 255, 194), true);
	DrawBoxAA(1400, 0, Screen::Width, Screen::Height, GetColor(246, 243, 194), true);

	DrawRoundRect(15, 15, 480, 120, 20, 20, GetColor(252, 246, 150), true);
	DrawStringToHandle(43, 40, "écÇËéûä‘:Å@Å@ïb", GetColor(255, 137, 72), m_fontHandle, GetColor(150, 40, 0));

	food.Draw();
}