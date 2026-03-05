#pragma once
#include "Food.h"
#include "FoodManager.h"
#include "SceneBase.h"

class SceneGame : public SceneBase
{
private:
	int m_fontHandle;

	FoodManager m_foodManager;

public:
	SceneGame() :
		m_fontHandle(0)
	{}

	virtual void Initialize()override;
	virtual void Finalize()override;
	virtual void Update()override;
	virtual void Draw()override;
};