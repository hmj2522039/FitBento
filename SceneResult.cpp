#include "SceneResult.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "SceneTitle.h"
#include "Screen.h"
#include "Input.h"
#include <string>


SceneResult::SceneResult(int score) :
    m_fontHandle(0)
{
    m_score = score;
}

void SceneResult::Initialize()
{
    // フォント
    m_fontHandle = CreateFontToHandle("HGP創英角ゴシックUB", 52, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

void SceneResult::Finalize()
{
    DeleteFontToHandle(m_fontHandle);
}

void SceneResult::Update()
{
    // スペースキーでタイトルへ戻る
    if (Input::IsSpaceDown())
    {
        SceneManager::GetInstance()->LoadScene(new SceneTitle());
    }
}

void SceneResult::Draw()
{
    // 背景
    DrawBox(0, 0, Screen::Width, Screen::Height, GetColor(246, 243, 194), true);
     
    // スコア表示
    DrawStringToHandle(
        Screen::Width / 2 - 150,
        Screen::Height / 2 - 50,
        ("スコア:" + std::to_string(m_score)).c_str(),
        GetColor(255, 137, 72),
        m_fontHandle
    );

    DrawStringToHandle(
        580, Screen::Height - 100,
        "スペースを押してタイトルに戻る",
        GetColor(255, 137, 72),
        m_fontHandle);
}
