#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
private:
	// ƒtƒHƒ“ƒg
	int m_fontHandle;
	int m_fontHandleTitle;

	static constexpr float WaitTransitionTime = 0.5f;

	float m_waitTransitionTime;

public:
	SceneTitle() :
		m_waitTransitionTime(WaitTransitionTime) { }

	virtual void Initialize()override;
	virtual void Finalize()override;
	virtual void Update()override;
	virtual void Draw()override;
};