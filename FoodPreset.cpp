#include "FoodPreset.h"
#include "DxLib.h"

std::vector<FoodTemplate> FoodPreset::CreateFoodTemplates()
{
	std::vector<FoodTemplate> foods;

	// この下に生成するおかずを記述
	FoodTemplate meatball;
	meatball.name = "ミートボール";
	meatball.tag = "meatball";
	meatball.imagePath = "Resource/meatball.png";
	meatball.parts.push_back({ 0, 0, 128, 128 });
	meatball.m_graph = LoadGraph(meatball.imagePath.c_str());
	foods.push_back(meatball);
	
	FoodTemplate tamagoyaki;
	tamagoyaki.name = "たまご焼き";
	tamagoyaki.tag = "tamagoyaki";
	tamagoyaki.imagePath = "Resource/tamagoyaki.png";
	tamagoyaki.parts.push_back({ 0, 0, 90, 225 });
	tamagoyaki.m_graph = LoadGraph(tamagoyaki.imagePath.c_str());
	foods.push_back(tamagoyaki);
	
	FoodTemplate sausage;
	sausage.name = "ソーセージ";
	sausage.tag = "sausage";
	sausage.imagePath = "Resource/sausage.png";
	sausage.parts.push_back({ 0, 0, 80, 320 });
	sausage.m_graph = LoadGraph(sausage.imagePath.c_str());
	foods.push_back(sausage);

	FoodTemplate edamame;
	edamame.name = "枝豆";
	edamame.tag = "edamame";
	edamame.imagePath = "Resource/edamame.png";
	edamame.parts.push_back({ 70,-35, 85, 120 });
	edamame.parts.push_back({ 0,60,220,70 });
	edamame.m_graph = LoadGraph(edamame.imagePath.c_str());
	foods.push_back(edamame);

	return foods;
}