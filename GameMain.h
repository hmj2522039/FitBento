#pragma once

// ゲームメインループ
class GameMain
{
private:
	int m_screen;	// 自作スクリーン
	int m_bgmHandle = -1;

public:
	GameMain() :
		m_screen(0) { }

	virtual ~GameMain();

	// メインループ実行
	void Run();

};