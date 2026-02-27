#pragma once
#include "Mouse.h"

class GameCore
{
private:
	Mouse mouse;

public:
	void Initialize();
	void Fialize();
	void Update();
	void Draw();
};