#include <vector>
#include "Cell.h"
#pragma once

using namespace std;


class Map
{
private:
	vector <vector <Cell>> my_map;
	int length;
	int width;
public:
	Map(int length, int width);
	int GetLength();
	int GetWidth();
	bool CheckFood(Vector2 x);
	void EatFood(Vector2 x);

	void PrintMap();
};

