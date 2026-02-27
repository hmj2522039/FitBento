#pragma once
#include "SceneBase.h"

class SceneLoading : public SceneBase
{
public:
	SceneLoading() {}

	virtual void Initialize() override;
	virtual void Finalize() override;
	virtual void Update() override;
	virtual void Draw() override;
};