#include "SceneGame.h"
#include "SceneResult.h"
#include "FoodPreset.h"
#include "FoodManager.h"
#include "Input.h"
#include "Screen.h"
#include "DxLib.h"
#include <string>

void SceneGame::Initialize()
{
	// 弁当箱画像読み込み
	int graph = LoadGraph("Resource/LunchBox.png");
	
	// フォント
	m_fontHandle = CreateFontToHandle("HGP創英角ゴシックUB", 52, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	// 弁当箱生成
	m_lunchBox = new LunchBox(graph, Vec2(200, 100));

	// 空きスペーススロット
	std::vector<BentoSlot> slots;
	{
		BentoSlot s;
		s.pos = Vec2(750, 350);
		s.parts.push_back({ 0, 0, 150, 150 });
		slots.push_back(s);
	}

	{
		BentoSlot s;
		s.pos = Vec2(750, 700);
		s.parts.push_back({ 0, 0, 50, 150 });
		slots.push_back(s);
	}

	m_lunchBox->SetSlots(slots);
	m_foodManager.SetSlots(slots);

	// おあずテンプレートの設定
	m_foodList.SetTemplates(FoodPreset::CreateFoodTemplates());

	// スコア・タイマー
	m_score = 0;
	m_timer = 90 * 60;

	m_lastGain = 0;
	m_gainTimer = 0;
}

void SceneGame::Finalize()
{
	if (m_lunchBox)
	{
		delete m_lunchBox;
		m_lunchBox = nullptr;
	}
}

void SceneGame::Update()
{
	// 制限時間
	m_timer--;
	if (m_timer <= 0)
	{
		SceneManager::GetInstance()->LoadScene(new SceneResult(m_score));
		return;
	}

	// すべてのスロットが埋まったら終了
	if (m_foodManager.GetLockedCount() >= (int)m_lunchBox->GetSlots().size())
	{
		SceneManager::GetInstance()->LoadScene(new SceneResult(m_score));
		return;
	}


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
	
	int gain = m_foodManager.PopLastGain();
	if (gain > 0)
	{
		m_score += gain;
		m_lastGain = gain;
		m_gainTimer = 60;
	}

	if (m_gainTimer > 0)
	{
		m_gainTimer--;
	}
}

void SceneGame::Draw()
{
	// 背景
	DrawBoxAA(0, 0, Screen::Width, Screen::Height, GetColor(246, 255, 194), true);

	// 弁当箱
	m_lunchBox->Draw();

	// おかずリスト側背景
	DrawBoxAA(Screen::Width - 520, 0, Screen::Width, Screen::Height, GetColor(246, 243, 194), true);

	// おかずリストを描画
	m_foodList.Draw();

	// おかずの描画
	m_foodManager.Draw();

	// スコア
	DrawRoundRect(Screen::Width - 950, 15, 1300, 120, 20, 20, GetColor(252, 246, 150), true);
	DrawStringToHandle(Screen::Width - 900, 40, ("スコア:" + std::to_string(m_score)).c_str(),GetColor(255, 137, 72), m_fontHandle);


	// 獲得スコア
	if (m_gainTimer > 0)
	{
		DrawStringToHandle(Screen::Width / 2 - 50, 80,
			("+" + std::to_string(m_lastGain)).c_str(),
			GetColor(255, 0, 0), m_fontHandle);
	}

	// 残り秒数表示
	DrawRoundRect(15, 15, 280, 120, 20, 20, GetColor(252, 246, 150), true);
	DrawStringToHandle(43, 40,
		("残り" + std::to_string(m_timer / 60) + "秒").c_str(),
		GetColor(255, 137, 72), m_fontHandle);
}