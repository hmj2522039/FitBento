#pragma once
#include "SceneBase.h"

class SceneResult : public SceneBase
{
private:
    int m_score = 0;

    int m_fontHandle;

public:
    SceneResult(int score);

    void Initialize() override;
    void Finalize() override;
    void Update() override;
    void Draw() override;
};
