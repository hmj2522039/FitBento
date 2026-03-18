#include "SceneTitle.h"
#include "SceneGame.h"
#include "Input.h"
#include "DxLib.h"


void SceneTitle::Initialize()
{

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
}