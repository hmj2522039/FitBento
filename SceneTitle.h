#pragma once
#include "SceneBase.h"
#include "Mouse.h"

class SceneTitle : public SceneBase
{
private:
	static constexpr float WaitTransitionTime = 0.5f;

	float m_waitTransitionTime;

	Mouse mouse;
public:
	SceneTitle() :
		m_waitTransitionTime(WaitTransitionTime) { }

	virtual void Initialize()override;
	virtual void Finalize()override;
	virtual void Update()override;
	virtual void Draw()override;
};