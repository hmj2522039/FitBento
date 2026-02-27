#pragma once
#include "SceneManager.h"

// ƒV[ƒ“‚ÌŠî’ê
class SceneBase
{
public:
	virtual ~SceneBase() {}

	virtual void Initialize() = 0;
	virtual void Finalize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};