#include "SceneTitle.h"
#include "SceneGame.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"


void SceneTitle::Initialize()
{
	// フォント
	m_fontHandle = CreateFontToHandle("HGP創英角ゴシックUB", 50, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	m_fontHandleTitle = CreateFontToHandle("HGP創英角ゴシックUB", 250, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

void SceneTitle::Finalize()
{

}

void SceneTitle::Update()
{
	if (Input::IsSpaceDown())
	{
		SceneManager::GetInstance()->LoadScene(new SceneGame());
	}
}

void SceneTitle::Draw()
{	
	// 背景
	DrawBoxAA(0, 0, Screen::Width, Screen::Height, GetColor(246, 255, 194), true);

	DrawStringToHandle(400, Screen::Height / 4,"Fit Bento",GetColor(255, 137, 72), m_fontHandleTitle,GetColor(255,200,72));
	DrawStringToHandle(640, Screen::Height - 300,"スペースを押してスタート",GetColor(255, 137, 72), m_fontHandle);
}