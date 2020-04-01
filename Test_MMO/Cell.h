#pragma once
#include "Vector2.h"

class Cell
{
private:

	Vector2 coordinate;

	bool food;

	void RandomFoodGenerate();

public:
	bool GetFood();
	void SetFood(bool x);
	Cell(int x , int y);
	Cell();


};

