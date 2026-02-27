#include "SceneLoading.h"
#include "Screen.h"
#include "DxLib.h"

void SceneLoading::Initialize()
{

}

void SceneLoading::Finalize()
{

}

void SceneLoading::Update()
{

}

void SceneLoading::Draw()
{
	DrawBoxAA(0, 0, Screen::Width, Screen::Height, GetColor(255, 255, 255), true);

	DrawFormatString(Screen::Width / 2, Screen::Height / 2, GetColor(0, 0, 0), "a");
}