#include "SceneBase.h"
#include "SceneManager.h"
#include "DxLib.h"

void SceneManager::Setup(SceneBase* initScene, SceneBase* loadingScene)
{
	SetUseASyncLoadFlag(false);
	m_loadingScene = loadingScene;
	if (m_loadingScene) m_loadingScene->Initialize();

	// 非同期読み込み開始
	// SetUseASyncLoadFlag(true);

	m_nextScene = initScene;
	m_phase = Phase::Setup;
}

void SceneManager::Dispose()
{
	// 実行中のシーンを破棄
	if (m_scene)
	{
		m_scene->Finalize();
		delete m_scene;
		m_scene = nullptr;
	}
	
	// 遷移先シーンを破棄
	if (m_nextScene)
	{
		m_nextScene->Finalize();
		delete m_nextScene;
		m_nextScene = nullptr;
	}

	// ローディングシーンを破棄
	if (m_loadingScene)
	{
		m_loadingScene->Finalize();
		delete m_loadingScene;
		m_loadingScene = nullptr;
	}
}

void SceneManager::LoadScene(SceneBase* scene)
{
	// シーンの切り替え中ならキャンセル
	if (m_nextScene)
	{
		delete scene;
		scene = nullptr;
		return;
	}

	m_nextScene = scene;
	m_phase = Phase::Setup;
}

void SceneManager::Update()
{
	switch (m_phase)
	{
	case Phase::Run:
		m_scene->Update();
		break;

	case Phase::Setup:
		m_nextScene->Initialize();

		if (m_scene)
		{
			m_scene->Finalize();
			delete m_scene;
			m_scene = nullptr;
		}

		m_phase = Phase::Loading;
		break;

	case Phase::Loading:
		if (m_loadingScene) m_loadingScene->Update();

		// ローディングが完了するまで待機
		if (GetASyncLoadNum() > 0)break;

		m_phase = Phase::Transition;
		break;

	case Phase::Transition:
		if (m_loadingScene) m_loadingScene->Update();

		// シーン遷移
		m_scene = m_nextScene;
		m_nextScene = nullptr;
		
		m_phase = Phase::Run;
		break;
	}
}

void SceneManager::Draw()
{
	if (m_scene)
	{
		m_scene->Draw();
	}

	if (m_loadingScene && (m_phase == Phase::Loading || m_phase == Phase::Transition))
	{
		m_loadingScene->Draw();
	}
}