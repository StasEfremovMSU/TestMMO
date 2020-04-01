#pragma once
#include <iostream>
#include "Vector2.h"
#include "item.h"

class plant : public item
{
private:
	int periodOfLife_;
	int periodOfFoodProduction_;
	std::string name_;
	int currentTimeLife_;
	int currentTimeLife_;
	Vector2 position;
	bool food;
public:
	plant();
	void MakeStep();
};

class Tree : public plant
{
	item ÑutDown();
};


