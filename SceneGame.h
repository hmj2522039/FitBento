#pragma once
#include "LunchBox.h"
#include "FoodList.h"
#include "FoodManager.h"
#include "SceneBase.h"

class SceneGame : public SceneBase
{
private:
    LunchBox* m_lunchBox = nullptr;
    FoodManager m_foodManager;
    FoodList m_foodList;

    int m_fontHandle;

    int m_score = 0;
    int m_timer = 90 * 60;

    int m_lastGain = 0;
    int m_gainTimer = 0;

public:
    SceneGame() :
    m_fontHandle(0)
    {}

    virtual void Initialize() override;
    virtual void Finalize() override;
    virtual void Update()override;
	virtual void Draw()override;
};