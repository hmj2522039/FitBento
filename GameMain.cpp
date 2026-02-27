#include "GameMain.h"
#include "GameConfig.h"
#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneLoading.h"
#include "Screen.h"
#include "DxLib.h"

GameMain::~GameMain()
{
	// 自作スクリーン破棄
	DeleteGraph(m_screen);

	DxLib_End();
}



void GameMain::Run()
{
	ChangeWindowMode(GameConfig::WindowMode);		// ウィンドウモード
	SetMainWindowText(GameConfig::Title);			// ウィンドウタイトル
	SetGraphMode(Screen::Width, 1080, GameConfig::ColorBit);	// ウィンドウサイズ
	SetAlwaysRunFlag(GameConfig::AlwaysRunFlag);	// 非アクティブ時の動作
	SetWaitVSyncFlag(false);

	if (DxLib_Init() == -1)
	{
		throw - 1;
	}

	// シーンの起動
	SceneManager::GetInstance()->Setup(new SceneTitle(), new SceneLoading());

	// スクリーン作成
	m_screen = MakeScreen(Screen::Width, Screen::Height);

	LONGLONG frameStartTime;

	while (true)
	{
		// フレームの開始時間を取得
		frameStartTime = GetNowHiPerformanceCount();

		if (ProcessMessage())
		{
			break;
		}

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		SceneManager::GetInstance()->Update();

		// 自作スクリーンに描画
		SetDrawScreen(m_screen);
		ClearDrawScreen();

		SceneManager::GetInstance()->Draw();

		// 自作スクリーンを裏画面に描画
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		DrawGraph(0, 0, m_screen, false);

		// 裏画面と表画面をひっくり返す
		ScreenFlip();

		// フレーム内の経過時間が指定したFPSになるまで待つ
		while (GetNowHiPerformanceCount() - frameStartTime < 1000000 / GameConfig::FPS);
	}

	SceneManager::GetInstance()->Dispose();
}