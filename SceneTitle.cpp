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
	mouse.Update();

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		SceneManager::GetInstance()->LoadScene(new SceneGame());
	}
}

void SceneTitle::Draw()
{
	mouse.Draw();
}