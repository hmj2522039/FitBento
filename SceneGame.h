#pragma once
#include "SceneBase.h"

class SceneGame : public SceneBase
{
public:
	SceneGame() {}

	virtual void Initialize()override;
	virtual void Finalize()override;
	virtual void Update()override;
	virtual void Draw()override;
};