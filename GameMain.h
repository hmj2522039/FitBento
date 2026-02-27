#pragma once
#include "GameCore.h"

// ゲームメインループ
class GameMain
{
private:
	int m_screen;	// 自作スクリーン
	GameCore gameCore;

public:
	GameMain() :
		m_screen(0) { }

	virtual ~GameMain();

	// メインループ実行
	void Run();

};