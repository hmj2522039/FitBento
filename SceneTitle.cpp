#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"


void SceneTitle::Initialize()
{

}

void SceneTitle::Finalize()
{

}

void SceneTitle::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		SceneManager::GetInstance()->LoadScene(new SceneGame());
	}
}

void SceneTitle::Draw()
{
}