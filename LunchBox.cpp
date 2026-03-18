#include "LunchBox.h"
#include "Vector2.h"
#include "Screen.h"
#include "DxLib.h"

void LunchBox::Initialize()
{
	m_image = LoadGraph("Resource/LunchBox.png");
}

void LunchBox::Update()
{



}

void LunchBox::Draw()
{
	DrawGraph(188, 50 + 50, m_image, true);
}
