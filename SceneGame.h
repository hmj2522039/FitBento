#pragma once
#include "Food.h"
#include "SceneBase.h"

class SceneGame : public SceneBase
{
private:
	int m_fontHandle;

	Food food;

public:
	SceneGame() :
		m_fontHandle(0),
		food(300, 300, 50, 50, 50)
	{}

	virtual void Initialize()override;
	virtual void Finalize()override;
	virtual void Update()override;
	virtual void Draw()override;
};