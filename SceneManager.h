#pragma once

class SceneBase;

class SceneManager
{
	enum class Phase
	{
		Run,		// 実行中
		Setup,		// 起動
		Loading,	// ローディング
		Transition, // 遷移
	};

	Phase m_phase;
	SceneBase* m_scene; // 実行中シーン
	SceneBase* m_nextScene;	// 遷移先
	SceneBase* m_loadingScene;	// ローディング

	SceneManager() :
		m_phase(Phase::Setup),
		m_scene(nullptr),
		m_nextScene(nullptr),
		m_loadingScene(nullptr){}

public:
	// シングルトンのインスタンスを取得
	static SceneManager* GetInstance()
	{
		static SceneManager instance;
		return &instance;
	}

	// 初期のシーンを設定する
	void Setup(SceneBase* initScene, SceneBase* loadingScene);

	// リソース解放
	void Dispose();

	void LoadScene(SceneBase* scene);

	void Update();
	void Draw();
};