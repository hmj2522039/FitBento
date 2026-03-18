#include "Food.h"
#include "FoodPreset.h"

std::vector<FoodTemplate> FoodPreset::CreateFoodTemplates()
{
	std::vector<FoodTemplate> foods;

	// ‚±‚Ì‰º‚É¶¬‚·‚é‚¨‚©‚¸‚ğ‹Lq
	FoodTemplate test;
	test.name = "test";
	test.parts.push_back({ -50, 0, 50, 150 });
	test.parts.push_back({ 0,50,150,50 });
	foods.push_back(test);
	
	FoodTemplate test2;
	test2.name = "test2";
	test2.parts.push_back({ 50, 0, 50, 150 });
	test2.parts.push_back({ 0,50,150,50 });
	foods.push_back(test2);
	
	FoodTemplate test3;
	test3.name = "test3";
	test3.parts.push_back({ 0, 0, 150, 150 });
	foods.push_back(test3);

	FoodTemplate test4;
	test4.name = "test4";
	test4.parts.push_back({ 50, 0, 50, 150 });
	test4.parts.push_back({ 0,-50,150,50 });
	foods.push_back(test4);

	FoodTemplate test5;
	test5.name = "test5";
	test5.parts.push_back({ -50, 0, 50, 150 });
	test5.parts.push_back({ 0,-50,150,50 });
	foods.push_back(test5);

	FoodTemplate test6;
	test6.name = "test6";
	test6.parts.push_back({ 0, 0, 50, 150 });
	test6.parts.push_back({ 0,50,150,50 });
	foods.push_back(test6);

	FoodTemplate test7;
	test7.name = "test7";
	test7.parts.push_back({ 0,0,50,150 });
	foods.push_back(test7);

	FoodTemplate test8;
	test8.name = "test8";
	test8.parts.push_back({ 0, 0, 150, 50 });
	foods.push_back(test8);

	return foods;
}