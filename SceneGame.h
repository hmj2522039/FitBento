#pragma once
#include "SceneBase.h"

class SceneGame : public SceneBase
{
private:
	int m_fontHandle;

public:
	SceneGame() :
		m_fontHandle(0)
	{}

	virtual void Initialize()override;
	virtual void Finalize()override;
	virtual void Update()override;
	virtual void Draw()override;
};